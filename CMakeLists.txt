cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(USERHOME $ENV{HOME})

# The following specify variables will used in pico-vscode.cmake
set(sdkVersion 2.1.1)
set(toolchainVersion RISCV_RPI_2_0_0_5)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
include(${picoVscode})

set(PICO_SDK_PATH ${USERHOME}/.pico-sdk/sdk/2.1.1)
set(PICO_BOARD pico2 CACHE STRING "Board type")
set(PICO_SDK_INIT_CMAKE_FILE ${PICO_SDK_PATH}/pico_sdk_init.cmake)

include(${PICO_SDK_INIT_CMAKE_FILE})

project(tetris_from_bare_metal C CXX ASM)

pico_sdk_init()

add_executable(tetris_from_bare_metal
    main.c
)

target_link_libraries(tetris_from_bare_metal pico_stdlib)

pico_add_extra_outputs(tetris_from_bare_metal)
