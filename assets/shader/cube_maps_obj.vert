#version 330 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormal;

out vec3 objPosition;
out vec3 objNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    objPosition = vec3(model * vec4(aPosition, 1.0));
    objNormal = mat3(transpose(inverse(model))) * aNormal;
    gl_Position = projection * view * model * vec4(aPosition, 1.0);
}
