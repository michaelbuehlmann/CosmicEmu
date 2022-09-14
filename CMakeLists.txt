cmake_minimum_required(VERSION 3.11)
project(CosmicEmu LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# PIC for everything (could be made target specific)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# By default, don't build the python libraries
option(PYTHON_LIBRARY "build the python library with pybind11?" ON)

# Sanitizer
# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address -g")
# set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-omit-frame-pointer -fsanitize=address -g")
# set (CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address -g")

# Dependencies
find_package(GSL REQUIRED)

# Python package
if(PYTHON_LIBRARY)
    include(FetchContent)
    FetchContent_Declare(
        pybind11
        GIT_REPOSITORY https://github.com/pybind/pybind11.git
        GIT_TAG v2.9.2
    )

    FetchContent_GetProperties(pybind11)
    if(NOT pybind11_POPULATED)
        FetchContent_Populate(pybind11)
        add_subdirectory(${pybind11_SOURCE_DIR} ${pybind11_BINARY_DIR})
    endif()
endif()

# Executables
add_subdirectory(2017-Mira-Titan-II)
add_subdirectory(2022-Mira-Titan-IV)

