cmake_minimum_required(VERSION 3.30)
project(HelloOpengl)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

file(
    GLOB_RECURSE MY_SOURCE src/*.c src/*.cpp
)

add_executable(HelloOpengl
    main.cpp
    ${MY_SOURCE}
)

target_link_libraries(HelloOpengl ${PROJECT_SOURCE_DIR}/lib/libassimp-5.dll)
target_link_libraries(HelloOpengl ${PROJECT_SOURCE_DIR}/lib/glfw3.dll)
