# Simple example

# build:
# 	g++ main.cpp -o main

# hello:
# 	echo "Hello, World"

# clean:
# 	rm -R main

# More complicated example, using a second, generalized, makefile

# System specifications
# F_CRYSTAL         = 8000000L
# F_CPU             = 72000000L
# SYSCLOCK          = SYSCLK_FREQ_72MHz
# FAMILY            = f37x
# USB               = enabled

# APPLICATION_LARGE = TRUE
# BOOTLOADER        = makeTest_bootloader

# Preferred upload command
# UPLOAD_COMMAND    = upload_combo_jtag_erase_first

# Packages to build
TARGET      	  = makeTest
PACKAGES          = makeTest \
				    makeTest/drivers
# 				    makeTest/dsp \
# 				    stm_audio_bootloader/fsk \
# 				    anolib/dsp \
# 				    anolib/utils \
# 				    anolib/system
# RESOURCES   	  = makeTest/resources

# TOOLCHAIN_PATH ?= /usr/local/arm-4.8.3/

include lib/makefile.inc
