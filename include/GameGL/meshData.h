#ifndef OPENGLPROJECT_INCLUDE_GAMEGL_MESHDATA_H_
#define OPENGLPROJECT_INCLUDE_GAMEGL_MESHDATA_H_

namespace basicTriangle
{
    const float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    const int indices[] = {
        0, 1, 2
    };
}

namespace quadZ
{
    const float vertices[] = {
        -0.5f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    const int indices[] = {
        0, 1, 2,
        1, 3, 2
    };
}

#endif
