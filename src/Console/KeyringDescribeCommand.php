<?php

declare(strict_types=1);

namespace Linux\KeyUtils\Console;

use Linux\KeyUtils\KeyDescription;
use Linux\KeyUtils\KeyUtilsLib;
use Symfony\Component\Console\Command\Command;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;

class KeyringDescribeCommand extends BaseCommand
{
    protected static $defaultName = 'keyring:describe';

    protected function configure(): void
    {
        $this
            ->addArgument('name', InputArgument::REQUIRED);
    }

    protected function execute(InputInterface $input, OutputInterface $output): int
    {
        $name = self::getStringArgument($input, 'name');

        $key = KeyUtilsLib::create()->describe_keyring((int) $name);

        $description = KeyDescription::fromKernelDescription($key);

        $output->writeln([
            "type: {$description->type}",
            "description: {$description->description}",
            "uid: {$description->uid}",
            "gid: {$description->gid}",
            "permissions: {$description->permissions->asHex()}",
        ]);

        return Command::SUCCESS;
    }
}
