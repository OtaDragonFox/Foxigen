#include "dragoncore.h"
#include "material.h"
#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include <Modules/IO/Logger.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n";





void material::compileShader(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	
	try
	{
		// open files
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		// read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// close file handlers
		vShaderFile.close();
		fShaderFile.close();
		// convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure& e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
	}
	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();
	


	//Vertex SHader !!!
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);


	checkRenderError(materialErrorType::vertex, vertexShader);

	//Fragment Shader!!
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	glCompileShader(fragmentShader);



	checkRenderError(materialErrorType::fragment, fragmentShader);


	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	checkRenderError(materialErrorType::program, shaderProgram);

	glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void material::checkRenderError(materialErrorType programType, int programIndex)
{
//vertex
	
	glGetShaderiv(programIndex, (programType == materialErrorType::program) ? GL_LINK_STATUS : GL_COMPILE_STATUS, &success);

	if (!success)
	{
		if (programType == materialErrorType::program)
		{
			if (!success)
			{
				glGetProgramInfoLog(programIndex, 512, NULL, infoLog);
				LOG("ERROR::SHADER::shaderProgram::COMPILATION_FAILED");
			}
		}
		else
		{
			glGetShaderInfoLog(programIndex, 512, NULL, infoLog);
			LOG("ERROR::SHADER::VERTEX::COMPILATION_FAILED");
		}
		LOG(infoLog);
	}
}

void material::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()),(int)value);
}

void material::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void material::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value);
}
