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

set(SRC_FILES
    src/button.c
    src/composite_shape.c
    src/game_controller.c
    src/game_model.c
    src/game_view.c
    src/gfx_graphics.c
    src/label.c
    src/main.c
    src/monitor.c
    src/rect.c
    src/utils.c
)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(LIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/lib)

project(tetris_from_bare_metal C CXX ASM)

pico_sdk_init()

add_subdirectory(${LIB_INCLUDE_DIR}/pico-displayDrivs)

add_executable(tetris_from_bare_metal
    ${SRC_FILES}
)

target_link_libraries(tetris_from_bare_metal pico_stdlib pico_multicore ili9341 gfx)
target_include_directories(tetris_from_bare_metal PRIVATE
    ${LIB_INCLUDE_DIR}
    ${INCLUDE_DIR}
)

pico_add_extra_outputs(tetris_from_bare_metal)
