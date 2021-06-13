<?php

declare(strict_types=1);

$finder = PhpCsFixer\Finder::create()
    ->in([
        __DIR__ . '/src',
    ]);

$config = new PhpCsFixer\Config();
return $config->setRules([
    '@PSR12' => true,
    'array_syntax' => ['syntax' => 'short'],
    'global_namespace_import' => true,
    'fully_qualified_strict_types' => true,
    'no_unused_imports' => true,
    'static_lambda' => true,
    'strict_param' => true,
    'strict_comparison' => true,
])
    ->setRiskyAllowed(true)
    ->setFinder($finder);
