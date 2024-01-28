# Notes

## Sources

- [Tutorial](https://kleinembedded.com/stm32-without-cubeide-part-1-the-bare-necessities/)
- [OpenOCD](https://openocd.org/doc/html/General-Commands.html)
- [MakeFiles](https://makefiletutorial.com)
- [GDB documentation](http://www.gnu.org/software/gdb/documentation/)
- [OpenOCD/GDB video](https://youtu.be/_1u7IOnivnM?si=yJdMDhAKt9oFQ0SB)

## Assumptions

- Building for _Nucleo-f401re_.

## Creating a project

Use _STM32CubeMX_ to generate a MakeFile project.

## Building and flashing

### Build

By default, this enables debugging. To change this, set DEBUG to 0.

* -ggdb
* No symbol table is loaded. Use the "file" command.

```zsh
cd $HOME/CLionProjects/AnoProjects/eModules/prototypes/secondblink
make
```

### Flash the board

Use OpenOCD and the built-in ST-LINK programmer on the nucleo board to flash the MCU. This requires identifying two files that come with OpeOCD - the first identifies the programmer used and the second identifies the MCU being tartgeted. "-f" is used to name a file, and "-c" is used to send commands to run.

```zsh
openocd -f interface/stlink-v2-1.cfg -f target/stm32f4x.cfg -c "program build/secondblink.elf verify reset"
```

To make this easier, add this to the MakeFile as described under __MakeFile customizations__ / _Flash the MCU_.

### Use GDB for debugging

In a _second terminal window_, start GDB with this command.

Navigate to the directory, identify the file with the symbol table, and start GDB on the elf file.

```zsh
arm-none-eabi-gdb build/secondblink.elf
```

At the (gdb) prompt, tell GDB where to find the nucleo board.

```zsh
target extended-remote localhost:3333
```

This should cause output like the following. Begin debugging.

    Reading symbols from build/secondblink.elf...
    (gdb) target extended-remote localhost:3333
    Remote debugging using localhost:3333
    0x080003ee in main () at Core/Src/main.c:106

#### GDB commands

From [here](https://www.tutorialspoint.com/gnu_debugger/gdb_commands.htm)

* __b main__ - Puts a breakpoint at the beginning of the program
* __b__ - Puts a breakpoint at the current line
* __b N__ - Puts a breakpoint at line N
* __b +N__ - Puts a breakpoint N lines down from the current line
* __b fn__ - Puts a breakpoint at the beginning of function "fn"
* __d N__ - Deletes breakpoint number N
* __info break__ - list breakpoints
* __r__ - Runs the program until a breakpoint or error
* __c__ - Continues running the program until the next breakpoint or error
* __f__ - Runs until the current function is finished
* __s__ - Runs the next line of the program
* __s N__ - Runs the next N lines of the program
* __n__ - Like s, but it does not step into functions
* __u N__ - Runs until you get N lines in front of the current line
* __p var__ - Prints the current value of the variable "var"
* __bt__ - Prints a stack trace
* __u__ - Goes up a level in the stack
* __d__ - Goes down a level in the stack
* __q__ - Quits gdb

Others

* __info registers__ - show register values

#### Folder structure

Note: Private development directories, denoted by the suffix "prv", are related to the top level directories shown below. Some of the items in these private folders will be copied into the directories below once they are ready for public consumption.

> __ano_lib__ - common files & files from ST used in the builds
  > __algos__ -
  > __dsp__ -
  > __fft__ -
  > __linker_scripts__ -
  > __midi__ -
  > __programming__ -
  > __system__ -
  > __test__ -
  > __third_party__ - HAL, CMSIS, etc. files from ST
  > __tools__ -
  > __ui__ -
  > __utils__ -
  > ____ -
> __<module name>__ - contains the name.c file & those it runs
  > __bootloader__ - bootloader unique to this module
  > __data__ - binaries included in what is stored on the module
  > __drivers__ - drivers unique to this module
  > __hardware_design__ - KiCad files, etc.
  > __python__ - scripts used to do pre-build things for this module
  > __tests__ - test scripts

### MakeFile customizations

#### Flash the MCU

Put this above clean.

```makefile
#######################################
# ADDED flash the MCU
#######################################
flash:
    openocd -f interface/stlink-v2-1.cfg -f target/stm32f4x.cfg -c "program build/secondblink.elf verify reset"
```

### Github Actions

To cause a build, update and push a new tag.

```zsh
git add --all
git commit -m "<text>"
git tag <tagname>
git push origin --tags
```

### Notes for above

#### Note 1

The _make_ command shown in the __Build__ section essentially does what is below...but the command would not work because it won't find main.h due to the directory structure. So, it is easier to use a MakeFile.

```zsh
arm-none-eabi-gcc Core/Src/main.c startup_stm32f401xe.s -T STM32F401RETx_FLASH.ld -o secondblink.elf -mcpu=cortex-m4 -mthumb -nostdlib
```

#### Note 2

To perform an object dump and save the output to a file.

```zsh
arm-none-eabi-objdump -D -b binary -marm build/secondblink.elf > logs/secondblink
```

### Forward looking

#### User flashing of devices

- Users' ability to flash devices using Docker and Vagrant is somewhat described [here](https://developer.hashicorp.com/vagrant/docs/providers/docker)
- Another point of view is presented [here](https://www.beningo.com/using-docker-to-setup-an-stm32-build-environment/)

