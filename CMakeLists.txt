cmake_minimum_required(VERSION 3.30)
project(HelloOpengl)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(HelloOpengl main.cpp src/glad.c hello_window.cpp hello_triangle.cpp hello_triangle_ebo.cpp
        hello_window.cpp
        include/my_config.h)
target_link_libraries(HelloOpengl ${PROJECT_SOURCE_DIR}/lib/glfw3.dll)
