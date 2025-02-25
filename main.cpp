#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

extern int hello_window_main();
extern int hello_triangle_main();
extern int hello_triangle_ebo_main();

int main()
{
    return hello_window_main();
}
