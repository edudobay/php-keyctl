<?php

declare(strict_types=1);

namespace Linux\KeyUtils;

use FFI\CData;

/**
 * @internal
 *
 * @method int add_key(string $type, string $description, ?string $payload, int $plen, int $keyring)
 * @method int request_key(string $type, string $description, ?string $callout_info, int $dest_keyring)
 * @method int keyctl_describe_alloc(int $id, CData $buffer)
 */
interface KeyUtilsFFIInterface
{
}
