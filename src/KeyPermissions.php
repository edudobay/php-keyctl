<?php

declare(strict_types=1);

namespace Linux\KeyUtils;

use function assert;
use function dechex;
use function hexdec;
use function is_int;

class KeyPermissions
{
    /** Permits the type, description and other parameters of a key to be viewed. */
    public const VIEW = 0x1;

    /** Permits the payload (or keyring list) to be read if supported by the type. */
    public const READ = 0x2;

    /** Permits the payload (or keyring list) to be modified or updated. */
    public const WRITE = 0x4;

    /** Search on a key permits it to be found when a keyring to which it is linked is searched. */
    public const SEARCH = 0x8;

    /** Permits a key to be linked to a keyring. */
    public const LINK = 0x10;

    /** Permits a key to have its owner, group membership, permissions mask and timeout changed. */
    public const SET_ATTRIBUTE = 0x20;

    public int $permissions;

    private function __construct(int $permissions)
    {
        $this->permissions = $permissions;
    }

    public static function fromHex(string $hexString): self
    {
        $asInt = hexdec($hexString);
        assert(is_int($asInt));
        return new self($asInt);
    }

    public function asHex(): string
    {
        return dechex($this->permissions);
    }
}
