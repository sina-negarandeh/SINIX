# SINIX

SINIX is an operating system cloned from [xv6](https://github.com/mit-pdos/xv6-public) with some added features. Xv6 is a modern reimplementation of Sixth Edition Unix in ANSI C for multiprocessor x86 and RISC-V systems, developed in the summer of 2006 for MIT's operating systems course. SINIX is the result of lab projects of operating systems course at the University of Tehran.

- [SINIX](#sinix)
  - [Added Features](#added-features)
    - [Part 1 (Introduction to XV6)](#part-1-introduction-to-xv6)
      - [Boot Message](#boot-message)
      - [ctrl + c](#ctrl--c)
      - [ctrl + x](#ctrl--x)
      - [ctrl + v](#ctrl--v)
      - [ctrl + b](#ctrl--b)
      - [ctrl + l](#ctrl--l)
      - [lcm](#lcm)
  - [How to use](#how-to-use)
    - [Building and Running xv6](#building-and-running-xv6)
      - [Building xv6](#building-xv6)
      - [Running xv6](#running-xv6)

## Added Features

### Part 1 (Introduction to XV6)

#### Boot Message

The operating system's name is added to the boot message.

#### ctrl + c

Copy all the text written on the current console line to the Clipboard.

#### ctrl + x

Cut all the text written on the current console line and copy it to the Clipboard.

#### ctrl + v

Paste the contents of the Clipboard.

#### ctrl + b

Replace the current text on the console with contents of the Clipboard.

#### ctrl + l

Clear the screen (terminal and CGA).

#### lcm

`lcm` is a user-level program written in C language, and it has been added to the operating system user-level programs. The program receives up to eight inputs and calculates their least common multiple. The program stores its output in a text file called `lcm_result.txt`. If the text file already exists, the output will be overwritten.

**Example:**

```shell
$ lcm 3 6 11 9
$ cat lcm_result.txt
198
```

## How to use

### Building and Running xv6

Xv6 typically is ran using the QEMU emulator.

#### Building xv6

To build xv6 on an x86 ELF machine, like Linux, run:

```shell
 make
```

On macOS, run:

```shell
make TOOLPREFIX=i386-elf-
```

#### Running xv6

To build everything and start QEMU with the CGA console (in a new window and the serial console in your terminal on an x86 ELF machine), like Linux, run:

```shell
make qemu
```

On macOS run:

```shell
make TOOLPREFIX=i386-elf- qemu
```

To exit, either close the CGA window or press `ctrl + c` or `ctrl + a` and then `x` in your terminal.

Like above, but to start with only the serial console on an x86 ELF machine, like Linux, run:

```shell
make qemu-nox
```

On macOS, run:

```shell
make TOOLPREFIX=i386-elf- qemu-nox
```

To exit, press `ctrl + a` and then `x`.
