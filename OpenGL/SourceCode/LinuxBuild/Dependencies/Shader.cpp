#include "Shader.h"
#include <GL/glew.h>
#include <iostream>
#include <string>
#include "Logging.h"
#include <fstream>
#include <sstream>
#include <cmath>

std::string vertex_source;
std::string fragment_source;
unsigned int shader;
int color_location;

unsigned int Shader::CompileShader(unsigned int type, std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);


	//error handling
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

		char* message = (char*)malloc(length * sizeof(char));

		glGetShaderInfoLog(id, length, &length, message);

		error(message);

		glDeleteShader(id);

		return 0;
	}

	return id;
}

unsigned int Shader::CreateShader(std::string& vertexShader, std::string& fragmentShader)
{
	unsigned int Program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(Program, vs);
	glAttachShader(Program, fs);
	glLinkProgram(Program);
	glValidateProgram(Program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return Program;
}

Shader::Shader(const std::string& file_path)
{
	enum class ShadeType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	ifstream stream(file_path);

	string line;
	stringstream ss[2];

	ShadeType type = ShadeType::NONE;

	while (getline(stream, line))
	{
		if (line.find("#shader") != string::npos)
		{

			if (line.find("vertex") != string::npos)
			{
				type = ShadeType::VERTEX;
			}

			else if (line.find("fragment") != string::npos)
			{
				type = ShadeType::FRAGMENT;
			}

		}
		else
		{
			ss[(int)type] << line << "\n";
		}
	}

	vertex_source = ss[0].str();
	fragment_source = ss[1].str();		
	shader = CreateShader(vertex_source, fragment_source);
}

void Shader::useShader()
{
	glUseProgram(shader);
}

void Shader::setColor(float red, float green, float blue, float alpha)
{
	int color_location = glGetUniformLocation(shader, "u_Color");
	glUniform4f(color_location, red, green, blue, alpha);
}

void Shader::deleteShader()
{
	glDeleteProgram(shader);
}
