# tetris-from-bare-metal

## Goal
This project is designed for learning Computer Systems. The goal is to build a playable Tetris game on bare metal using a Raspberry Pi Pico 2 and its peripherals.

The process will be divided into several phases:
1. Knowing how to interact between Pico 2 and the devices. (button, screen, etc.)
2. Constructing the Tetris game using the built-in SDK.
3. Progressively replacing SDK modules with custom-written ones.
4. Aiming for a build that's as close to Bare Metal as possible.

## How to run the project
### Using Debug Probe (Another Pico 2)
**Monitor the outputs**
```bash
# You need to find your Debug Probe tty first
# by typing 'ls /dev/' and looking for tty.usbmodemxxxx / tty.ACMxx
$ minicom -D /dev/tty.usbmodem1202 -b 115200
```
**GDB**
```bash
# Prepare OpenOCD server
$ sudo openocd -f interface/cmsis-dap.cfg -f target/rp2350-riscv.cfg -c "adapter speed 5000"

# Open another terminal. Go to the project directory.
$ rm -rf build
$ mkdir build
$ cmake ..
$ make -j4
$ gdb blink.elf
> target remote localhost:3333
> load
> monitor reset init
> continue
```
