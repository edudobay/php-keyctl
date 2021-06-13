<?php

declare(strict_types=1);

namespace Linux\KeyUtils;

use function count;
use function explode;

class KeyDescription
{
    private const FIELDS_COUNT = 5;

    public function __construct(
        public string $type,
        public int $uid,
        public int $gid,
        public KeyPermissions $permissions,
        public string $description
    ) {
    }

    public static function fromKernelDescription(string $rawDescription): self
    {
        $fields = explode(';', $rawDescription);
        if (count($fields) !== self::FIELDS_COUNT) {
            throw new KeyUtilsException(sprintf(
                'Invalid description: expected %d fields, got %d instead',
                self::FIELDS_COUNT,
                count($fields)
            ));
        }

        return new self(
            type: $fields[0],
            uid: (int) $fields[1],
            gid: (int) $fields[2],
            permissions: KeyPermissions::fromHex($fields[3]),
            description: $fields[4]
        );
    }
}
