# PHP interface to Linux Key Management Utilities

I was very interested when I heard about the Key Management features in the Linux kernel, so I decided to learn a bit about it and how to use it in PHP. I did not find anything ready for PHP so I started this draft.

More information about the Key Management Utilities:

* [Man page](https://man7.org/linux/man-pages/man7/keyutils.7.html) at man7.org (`man 7 keyutils`)
* Git repository: at [git.kernel.org](https://git.kernel.org/pub/scm/linux/kernel/git/dhowells/keyutils.git/) or at [kernel.googlesource.com](https://kernel.googlesource.com/pub/scm/linux/kernel/git/dhowells/keyutils)

## Setup, technical details, etc.

🚧 🚧 🚧 This is still an experiment and there's no useful functionality here!

This project requires PHP 8.0+, with the `ffi` and `posix` PHP extensions (this is declared in `composer.json`).

Run `composer install` to install dependencies.
* During experimentation, the [Symfony Console](https://symfony.com/doc/current/components/console.html) was added as a dependency. If this project goes forward, the goal is to have no dependencies.
