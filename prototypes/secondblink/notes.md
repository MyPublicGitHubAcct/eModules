# Notes

## Sources

[link 1](https://kleinembedded.com/stm32-without-cubeide-part-1-the-bare-necessities/).

## Building and flashing

- Build

```zsh
arm-none-eabi-gcc Core/Src/main.c startup_stm32f401xe.s -T STM32F401RETx_FLASH.ld -o secondblink.elf -mcpu=cortex-m4 -mthumb -nostdlib
```

The command above, essentially, does what is below...but would not work because it won't fine main.h due to the directory structure. So, it is best to use a MakeFile like -

```zsh
cd $HOME/CLionProjects/AnoProjects/eModules/prototypes/secondblink
make
```

- Flash the board

Use OpenOCD and the built-in ST-LINK programmer on the nucleo board to flash the MCU.

```zsh
cd build
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program secondblink.elf verify reset exit"
```




