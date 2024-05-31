cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


project(dead_beef)

# Include the library subdirectory
add_subdirectory(lib/RenderingEngine)

# Include the application subdirectory
add_subdirectory(app)
