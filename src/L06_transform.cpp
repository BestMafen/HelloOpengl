//
// Created by bestm on 2025/3/1.
//
#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

int L06_transform_main() {
    glm::vec4 vec(1.f, .0f, .0f, 1.f);
    glm::mat4 trans;
    trans = glm::translate(trans, glm::vec3(1.f, 1.f, .0f));
    vec = trans * vec;
    std::cout << "x=" << vec.x << ", y=" << vec.y << ", z=" << vec.z << std::endl;

    return 0;
}
