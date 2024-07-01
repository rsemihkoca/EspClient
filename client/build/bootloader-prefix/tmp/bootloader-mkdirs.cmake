# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/rsemihkoca/esp/esp-idf/components/bootloader/subproject"
  "/home/rsemihkoca/Projects/EspClient/client/build/bootloader"
  "/home/rsemihkoca/Projects/EspClient/client/build/bootloader-prefix"
  "/home/rsemihkoca/Projects/EspClient/client/build/bootloader-prefix/tmp"
  "/home/rsemihkoca/Projects/EspClient/client/build/bootloader-prefix/src/bootloader-stamp"
  "/home/rsemihkoca/Projects/EspClient/client/build/bootloader-prefix/src"
  "/home/rsemihkoca/Projects/EspClient/client/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/rsemihkoca/Projects/EspClient/client/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/rsemihkoca/Projects/EspClient/client/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
