cmake_minimum_required(VERSION 3.15.3)

project(test)

add_subdirectory(Catch2)

# These tests can use the Catch2-provided main
add_executable(tests test.cpp
        ../CubeMX_files/Src/rgb_hsl_hsv.c
)

target_include_directories(tests PRIVATE
    ../CubeMX_files/Inc)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
