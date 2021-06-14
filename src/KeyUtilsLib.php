<?php

declare(strict_types=1);

namespace Linux\KeyUtils;

use FFI;
use InvalidArgumentException;

use function ctype_digit;
use function posix_get_last_error;
use function strlen;

class KeyUtilsLib
{
    /** key ID for thread-specific keyring */
    public const KEY_SPEC_THREAD_KEYRING = -1;
    /** key ID for process-specific keyring */
    public const KEY_SPEC_PROCESS_KEYRING = -2;
    /** key ID for session-specific keyring */
    public const KEY_SPEC_SESSION_KEYRING = -3;
    /** key ID for UID-specific keyring */
    public const KEY_SPEC_USER_KEYRING = -4;
    /** key ID for UID-session keyring */
    public const KEY_SPEC_USER_SESSION_KEYRING = -5;
    /** key ID for GID-specific keyring */
    public const KEY_SPEC_GROUP_KEYRING = -6;
    /** key ID for assumed request_key auth key */
    public const KEY_SPEC_REQKEY_AUTH_KEY = -7;

    /** @var FFI&KeyUtilsFFIInterface */
    private FFI $ffi;

    /** @var FFI&LibCInterface */
    private FFI $libc;

    /**
     * @param FFI&KeyUtilsFFIInterface $ffi
     */
    public function __construct(FFI $ffi)
    {
        $this->ffi = $ffi;
        /** @var FFI&LibCInterface $libc */
        $libc = FFI::cdef('void free (void* ptr);', "libc.so.6");
        $this->libc = $libc;
    }

    public static function create(): self
    {
        /** @var FFI&KeyUtilsFFIInterface $ffi */
        $ffi = FFI::load(__DIR__ . '/keyutils.h');
        return new self($ffi);
    }

    /**
     * @param array<array-key, mixed> $context
     */
    private function exception(array $context = [], ?int $errno = null): KeyUtilsException
    {
        $errno ??= posix_get_last_error();
        if ($errno === KeyUtilsException::ENOKEY) {
            throw KeyNotFoundException::forKey($context['type'], $context['description']);
        }
        throw KeyUtilsException::fromError($errno);
    }

    public function resolve_key_spec(string $spec): int
    {
        if (ctype_digit($spec)) {
            return (int) $spec;
        }

        return match ($spec) {
            "@t" => self::KEY_SPEC_THREAD_KEYRING,
            "@p" => self::KEY_SPEC_PROCESS_KEYRING,
            "@s" => self::KEY_SPEC_SESSION_KEYRING,
            "@u" => self::KEY_SPEC_USER_KEYRING,
            "@us" => self::KEY_SPEC_USER_SESSION_KEYRING,
            "@g" => self::KEY_SPEC_GROUP_KEYRING,
            "@a" => self::KEY_SPEC_REQKEY_AUTH_KEY,
            default => throw new InvalidArgumentException("not supported: $spec"),
        };
    }

    public function add_keyring(string $name, string $parent): int
    {
        $parentKeyId = self::resolve_key_spec($parent);

        $keySerial = $this->ffi->add_key("keyring", $name, null, 0, $parentKeyId);
        if ($keySerial < 0) {
            throw self::exception();
        }

        return $keySerial;
    }

    public function add_key(string $name, string $data, string $parent): int
    {
        $parentKeyId = self::resolve_key_spec($parent);

        $type = "user";

        $keySerial = $this->ffi->add_key($type, $name, $data, strlen($data), $parentKeyId);
        if ($keySerial < 0) {
            throw self::exception();
        }

        return $keySerial;
    }

    public function request_key(string $type, string $description): int
    {
        $keySerial = $this->ffi->request_key($type, $description, null, 0);
        if ($keySerial < 0) {
            throw self::exception(['type' => $type, 'description' => $description]);
        }

        return $keySerial;
    }

    public function describe_keyring(int $id): string
    {
        /** @var FFI\CDataArray $buffer */
        $buffer = FFI::new('char*[1]');

        $size = $this->ffi->keyctl_describe_alloc($id, FFI::addr($buffer[0]));
        if ($size < 0) {
            throw self::exception();
        }

        $description = FFI::string($buffer[0], $size);

        // Buffer returned by `keyctl_describe_alloc` must be freed (FFI::free won't work)
        $this->libc->free($buffer[0]);

        return $description;
    }

    public function read_key(string $keySpec): string
    {
        /** @var FFI\CDataArray $buffer */
        $buffer = FFI::new('char*[1]');

        $id = $this->resolve_key_spec($keySpec);

        $size = $this->ffi->keyctl_read_alloc($id, FFI::addr($buffer[0]));
        if ($size < 0) {
            throw self::exception();
        }

        $description = FFI::string($buffer[0], $size);

        // Buffer returned by `keyctl_describe_alloc` must be freed (FFI::free won't work)
        $this->libc->free($buffer[0]);

        return $description;
    }
}
