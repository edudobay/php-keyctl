<?php

declare(strict_types=1);

namespace Linux\KeyUtils\Console;

use Symfony\Component\Console\Command\Command;
use Symfony\Component\Console\Input\InputInterface;

abstract class BaseCommand extends Command
{
    public static function getStringArgument(InputInterface $input, string $name): string
    {
        $value = $input->getArgument($name);
        \assert(\is_string($value));
        return $value;
    }
}
