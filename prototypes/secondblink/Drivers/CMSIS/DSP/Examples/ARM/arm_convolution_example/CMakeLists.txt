cmake_minimum_required (VERSION 3.14)
project (arm_convolution_example VERSION 0.1)


# Needed to include the configBoot module
# Define the path to CMSIS-DSP (ROOT is defined on command line when using cmake)
set(ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../../../..)
set(DSP ${ROOT}/CMSIS/DSP)

# Add DSP folder to module path
list(APPEND CMAKE_MODULE_PATH ${DSP})

################################### 
#
# LIBRARIES
#
###################################

########### 
#
# CMSIS DSP
#

add_subdirectory(../../../Source bin_dsp)


################################### 
#
# TEST APPLICATION
#
###################################


add_executable(arm_convolution_example)


include(config)
configApp(arm_convolution_example ${ROOT})

target_sources(arm_convolution_example PRIVATE arm_convolution_example_f32.c math_helper.c)

### Sources and libs

target_link_libraries(arm_convolution_example PRIVATE CMSISDSP)

