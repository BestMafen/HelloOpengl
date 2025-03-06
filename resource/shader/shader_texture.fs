#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 texCoord;

uniform sampler2D ourSampler;
uniform sampler2D ourSampler1;

void main()
{
    FragColor = mix(texture(ourSampler, texCoord), texture(ourSampler1, texCoord), 0.2);
}
