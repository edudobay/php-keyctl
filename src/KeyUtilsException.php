<?php

declare(strict_types=1);

namespace Linux\KeyUtils;

use RuntimeException;

use function posix_strerror;

class KeyUtilsException extends RuntimeException
{
    public const ENOKEY = 126;

    /** @psalm-pure */
    public static function fromError(int $errno, ?string $detailMessage = null): self
    {
        $message = posix_strerror($errno);
        if ($detailMessage) {
            $message .= "\n" . $detailMessage;
        }

        return new self($message, $errno);
    }
}
