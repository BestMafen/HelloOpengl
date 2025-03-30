#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoor;

out vec2 texCoord;

out VS_OUT {
    vec3 pos;
    vec3 normal;
    vec2 texCoor;
    vec4 lightSpacePos;
} vs_out;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 lightSpaceMatrix;

void main()
{
    vs_out.pos = vec3(model * vec4(aPos, 1.0));
    vs_out.normal = transpose(inverse(mat3(model))) * aNormal;
    vs_out.texCoor = aTexCoor;
    vs_out.lightSpacePos = lightSpaceMatrix * vec4(vs_out.pos, 1.0);
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
