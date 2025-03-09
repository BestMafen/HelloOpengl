#version 330 core
out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D sampleCube;

float near = 0.1;
float far = 100.0;

float LinearizeDepth(float depth)
{
    float z = depth * 2.0 - 1.0; // 转换为 NDC
    return (2.0 * near * far) / (far + near - z * (far - near));
}

void main()
{
    FragColor = texture(sampleCube, texCoord);
//    float depth = LinearizeDepth(gl_FragCoord.z) / far; // 为了演示除以 far
//    FragColor = vec4(vec3(depth), 1.0);
}
