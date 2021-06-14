<?php

declare(strict_types=1);

namespace Linux\KeyUtils\Console;

use Linux\KeyUtils\KeyUtilsLib;
use Symfony\Component\Console\Command\Command;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;

use function file_get_contents;

class KeyAddCommand extends BaseCommand
{
    protected static $defaultName = 'key:add';

    protected function configure(): void
    {
        $this
            ->addArgument('name', InputArgument::REQUIRED)
            ->addArgument('parent', InputArgument::REQUIRED);
    }

    protected function execute(InputInterface $input, OutputInterface $output): int
    {
        $name = self::getStringArgument($input, 'name');
        $parent = self::getStringArgument($input, 'parent');

        $data = file_get_contents('php://stdin');
        assert(is_string($data));

        $key = KeyUtilsLib::create()->add_key($name, $data, $parent);
        $output->writeln((string) $key);
        return Command::SUCCESS;
    }
}
