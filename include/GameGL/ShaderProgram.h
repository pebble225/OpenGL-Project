#include <GL/glew.h>

#ifndef SHADERPROGRAM_INCLUDE_GAMEGL_SHADERPROGRAM_H_
#define SHADERPROGRAM_INCLUDE_GAMEGL_SHADERPROGRAM_H_

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class ShaderProgram
{
private:
    static std::string getShaderCode(std::string src);
    static GLuint createShader(std::string src, GLuint shaderType);

    GLuint shaderprogram;
public:
    ShaderProgram();

    void initBasicShaderProgram(std::string vertexShaderFile, std::string fragmentShaderFile);

	void use();
	void unuse();

    ~ShaderProgram();
};

#endif