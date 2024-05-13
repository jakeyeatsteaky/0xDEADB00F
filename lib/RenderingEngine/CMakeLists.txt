cmake_minimum_required(VERSION 3.10)

# Define the library
project(RenderingEngine)

# Create the library target
add_library(RenderingEngine STATIC
    src/RenderingEngine.cpp
    src/Utility.cpp
    src/Logger.cpp
    src/Renderer.cpp
)

# Specify the include directories for the library
target_include_directories(RenderingEngine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
