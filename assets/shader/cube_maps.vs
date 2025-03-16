#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 aTextureCoord;

uniform mat4 view;
uniform mat4 projection;

void main()
{
    aTextureCoord = aPos;
    vec4 pos = vec4(projection * view * vec4(aPos, 1.0));
    gl_Position = pos.xyww;
}
