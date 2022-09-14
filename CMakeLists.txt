cmake_minimum_required(VERSION 3.11)
project(CosmicEmu LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# PIC for everything (could be made target specific)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Sanitizer
# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address -g")
# set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-omit-frame-pointer -fsanitize=address -g")
# set (CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address -g")

# Dependencies
find_package(GSL REQUIRED)

# Executables
add_subdirectory(2017-Mira-Titan-II)
add_subdirectory(2022-Mira-Titan-IV)
