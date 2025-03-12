#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

extern int L01_window_main();
extern int L02_triangle_main();
extern int L03_triangle_ebo_main();
extern int L04_shader_main();
extern int L05_texture_main();
extern int L06_transform_main();
extern int L07_coordinate_main();
extern int L08_camera_main();
extern int L08_camera_class_main();
extern int L09_basic_lighting_main();
extern int L10_material_main();
extern int L11_lighting_maps_main();
extern int L12_light_caster_main();
extern int L12_light_caster1_main();
extern int L13_multiple_lights_main();
extern int L14_model_main();
extern int L15_depth_testing_main();
extern int L16_stencil_testing_main();
extern int L17_blending_main();

int main()
{
    return L17_blending_main();
}
