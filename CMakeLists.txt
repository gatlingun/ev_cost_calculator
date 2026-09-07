cmake_minimum_required(VERSION 3.16)

project(ev_cost_calculator
    VERSION 0.1.0
    LANGUAGES CXX
)

# Support the standard Qt online-installer location on macOS, so a plain
# `cmake -S . -B build` works without requiring CMAKE_PREFIX_PATH each time.
list(PREPEND CMAKE_PREFIX_PATH "$ENV{HOME}/Qt/6.11.2/macos")

add_subdirectory(src)
