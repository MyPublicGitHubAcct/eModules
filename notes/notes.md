# Developing on STM32 MCU's

## ------------------------------------------------------------------------
## First steps - Blink
## ------------------------------------------------------------------------

### Install STM32CubeMX

Download the installer from st.com.

Make the CubeMX and java installers able to run using this command.

```shell
sudo xattr -cr /Users/home/Downloads/en.stm32cubemx-mac-v6-9-2/
```

Extract the files and run the installer.

### Install ARM's toolchain

Make a folder to hold various things related to embedded development, but not to any specific projects.

```shell
mkdir ~/Embedded
```

Get the arm toolchain from https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads.

In this case, downloaded the 32-bit version of arm-none-eabi for mac. - _arm-gnu-toolchain-12.3.rel1-darwin-arm64-arm-none-eabi.tar.xz_ & unzipped it into __~/Embedded__.


Tp update system PATH so CLion can find the toolchain, add it to zshell's profile file like ```nano ~/.zprofile```.


```shell
# Setting PATH for ARM toolchain 12.3.rel1
export PATH=$PATH:~/Embedded/arm-gnu-toolchain-12.3.rel1-darwin-arm64-arm-none-eabi/bin
```

Test with:

- ```echo $PATH```
- ```arm-none-eabi-gcc --version```


### Install OpenOCD

On mac, install with Homebrew.

```shell
brew install open-ocd
```

Test with:

- ```openocd --version```

You now have OpenOCD installed to /opt/homebrew/bin/openocd. Configure that path in CLion's embedded configuration.


### Test program, firstblink

?

## ------------------------------------------------------------------------
## Structure of repos
## ------------------------------------------------------------------------

### Ano_Releases (main public repo)

- binary files that are installed on modules
- webapps used to generate content loaded on modules
- open-sourced code
- manuals (in pdf)

### stfiles (public repo)

- files (all open source) from st, used to compile the binaries
- files (all open source) from other developers

### eModules (private repo)

- module code not publicly released (under dev or not yet profitable)
- module code publicly released (source of Ano_Releases)
- learning information
- notes (to self - this file is one of them)
- prototypes and tests of code run on MCU's

### anolib (private repo)

- base or commonly used dsp, ui, etc. in modules
- test cases for the code in this library
- python used to define algos
