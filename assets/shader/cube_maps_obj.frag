#version 330 core
out vec4 FragColor;

in vec3 objPosition;
in vec3 objNormal;

uniform vec3 cameraPosition;
uniform samplerCube samplerSkybox;

void main()
{
    vec3 I = normalize(objPosition - cameraPosition);
//    // 反射
//    vec3 R = reflect(I, normalize(objNormal));
    // 折射
    float ratio = 1.00 / 1.52;
    vec3 R = refract(I, normalize(objNormal), ratio);
    FragColor = vec4(texture(samplerSkybox, R).rgb, 1.0);
}
