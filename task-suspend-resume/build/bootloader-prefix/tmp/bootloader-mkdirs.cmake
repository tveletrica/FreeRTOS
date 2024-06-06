# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/ferna/esp/v4.4.5/esp-idf/components/bootloader/subproject"
  "C:/Users/ferna/OneDrive/Desktop/house/ESP_IDF_TV_eletrica/FreeRTOS/task-suspend-resume/build/bootloader"
  "C:/Users/ferna/OneDrive/Desktop/house/ESP_IDF_TV_eletrica/FreeRTOS/task-suspend-resume/build/bootloader-prefix"
  "C:/Users/ferna/OneDrive/Desktop/house/ESP_IDF_TV_eletrica/FreeRTOS/task-suspend-resume/build/bootloader-prefix/tmp"
  "C:/Users/ferna/OneDrive/Desktop/house/ESP_IDF_TV_eletrica/FreeRTOS/task-suspend-resume/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/ferna/OneDrive/Desktop/house/ESP_IDF_TV_eletrica/FreeRTOS/task-suspend-resume/build/bootloader-prefix/src"
  "C:/Users/ferna/OneDrive/Desktop/house/ESP_IDF_TV_eletrica/FreeRTOS/task-suspend-resume/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/ferna/OneDrive/Desktop/house/ESP_IDF_TV_eletrica/FreeRTOS/task-suspend-resume/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
