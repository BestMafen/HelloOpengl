#version 330 core
out vec4 FragColor;

in vec3 aTextureCoord;

uniform samplerCube samplerSkybox;

void main()
{
    FragColor = texture(samplerSkybox, aTextureCoord);
}
