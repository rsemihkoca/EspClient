# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
set(CMAKE_FIND_ROOT_PATH /home/rsemihkoca/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20240530/xtensa-esp-elf/)
set(CMAKE_C_COMPILER  /home/rsemihkoca/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20240530/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc)
set(CMAKE_CXX_COMPILER  /home/rsemihkoca/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20240530/xtensa-esp-elf/bin/xtensa-esp32-elf-g++)
set(CMAKE_ASM_COMPILER /home/rsemihkoca/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20240530/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc)
project(client)
