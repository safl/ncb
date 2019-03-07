# NVMe command builder

The liblightnvm CLI has a tool to pass through NVMe commands with minimal
intervention. This can be used for e.g. fuzz-testing your device by sending an
random sequence of bits, or literally whatever you might want to do.

The 64 bytes defining the NVMe command is given to the CLI tool as a path to a
binary file. Since flipping those bits by hand is a bit cumbersome then this
tool lets you assign the various bits and bytes, via the C definition, and dumps
the command to file.

It requires a C compiler, the `xxd` tool, and the liblightnvm headers installed
on your system.

# Usage

Open `ncb.c` with your favorite editor. Assign values as you see fit to the NVMe
command, that is, the variable named `cmd`.

Then run:

```
make
```

The `make` compiles the program that creates the structure. Runs it, dumping the
structure to the file `build/your.ncmd`. Prints it out with `xxd`.

## Example

```
make
# Cleaning build
# Building ncb.c
# Running build/ncb
# Inspecting build/your.ncmd
00000000: 00000001 00000000 00000000 00000000  ....
00000004: 00000001 00000000 00000000 00000000  ....
00000008: 00000000 00000000 00000000 00000000  ....
0000000c: 00000000 00000000 00000000 00000000  ....
00000010: 00000000 00000000 00000000 00000000  ....
00000014: 00000000 00000000 00000000 00000000  ....
00000018: 00000000 00000000 00000000 00000000  ....
0000001c: 00000000 00000000 00000000 00000000  ....
00000020: 00000000 00000000 00000000 00000000  ....
00000024: 00000000 00000000 00000000 00000000  ....
00000028: 00000000 00000000 00000000 00000000  ....
0000002c: 00000000 00000000 00000000 00000000  ....
00000030: 00000100 00000000 00000000 00000000  ....
00000034: 00000000 00000000 00000000 00000000  ....
00000038: 00000000 00000000 00000000 00000000  ....
0000003c: 00000000 00000000 00000000 00000000  ....
# DONE
```
