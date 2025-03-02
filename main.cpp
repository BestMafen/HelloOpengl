#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

extern int hello_coordinate_main();
extern int hello_shader_main();
extern int hello_texture_main();
extern int hello_transform_main();
extern int hello_triangle_ebo_main();
extern int hello_triangle_main();
extern int hello_window_main();

int main()
{
    return hello_coordinate_main();
}
