#version 330 core

layout (location = 0) in vec3 pos;

out vec4 vertexColor;

void main(void)
{
    gl_Position = vec4(pos, 1.0);
    vertexColor(0.2, 0.9, 0.0, 1.0);
}
