<?php

declare(strict_types=1);

namespace Linux\KeyUtils;

class KeyNotFoundException extends KeyUtilsException
{
    public static function forKey(string $type, string $description): self
    {
        return new self(
            "Key not found: <$type> $description",
            self::ENOKEY
        );
    }
}
