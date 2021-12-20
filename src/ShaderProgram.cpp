#include <GameGL/ShaderProgram.h>

ShaderProgram::ShaderProgram()
{

}

std::string ShaderProgram::getShaderCode(std::string src)
{
	std::ifstream shaderFile;

	shaderFile.open(src);

	std::string code;
	std::string line;

	if (shaderFile.is_open())
	{
		while (getline(shaderFile, line))
		{
			code += line;
			code += "\n";
		}

		shaderFile.close();
	}
	else
	{
		std::cout << "Unable to open shader at \"" << src << "\"." << std::endl;
	}

	return code;
}

GLuint ShaderProgram::createShader(std::string src, const GLuint shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	int result;
	char infoLog[512];

	std::string shaderCode = ShaderProgram::getShaderCode(src);

	const char* shaderCode_cstr = shaderCode.c_str();
	glShaderSource(shader, 1, &shaderCode_cstr, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	if (!result)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "Error when compiling \"" << src << "\":" << infoLog << std::endl;
	}

    return shader;
}

void ShaderProgram::initBasicShaderProgram(std::string vertexShaderFile, std::string fragmentShaderFile)
{
	shaderprogram = glCreateProgram();

	GLuint vertexShader, fragmentShader;

	vertexShader = ShaderProgram::createShader(vertexShaderFile, GL_VERTEX_SHADER);
	fragmentShader = ShaderProgram::createShader(fragmentShaderFile, GL_FRAGMENT_SHADER);

	glAttachShader(shaderprogram, vertexShader);
	glAttachShader(shaderprogram, fragmentShader);
	glLinkProgram(shaderprogram);

	int status;
	char infoLog[512];

	glGetProgramiv(shaderprogram, GL_LINK_STATUS, &status);
	
	if (!status)
	{
		glGetProgramInfoLog(shaderprogram, 512, NULL, infoLog);
		std::cout << "Error when compiling basic shader program: " << infoLog << std::endl;
	}

	glDetachShader(shaderprogram, vertexShader);
	glDetachShader(shaderprogram, fragmentShader);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void ShaderProgram::use()
{
	glUseProgram(shaderprogram);
}

void ShaderProgram::unuse()
{
	glUseProgram(0);
}

ShaderProgram::~ShaderProgram()
{

}