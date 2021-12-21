#version 330 core

layout(location = 0) in vec3 pos;

uniform mat4 position;
uniform mat4 camera;
uniform mat4 orthographic;

void main()
{
    gl_Position = vec4(pos, 1.0);
}
