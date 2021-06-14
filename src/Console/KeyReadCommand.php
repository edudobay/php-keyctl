<?php

declare(strict_types=1);

namespace Linux\KeyUtils\Console;

use Linux\KeyUtils\KeyUtilsLib;
use Symfony\Component\Console\Command\Command;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;

class KeyReadCommand extends BaseCommand
{
    protected static $defaultName = 'key:read';

    protected function configure(): void
    {
        $this
            ->addArgument('keyId', InputArgument::REQUIRED);
    }

    protected function execute(InputInterface $input, OutputInterface $output): int
    {
        $keyId = self::getStringArgument($input, 'keyId');

        $keyData = KeyUtilsLib::create()->read_key($keyId);
        $output->write($keyData);
        return Command::SUCCESS;
    }
}
