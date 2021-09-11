#pragma once
#include <iostream>
#include <string>

// class for creating Shaders
class Shader
{
private:

	unsigned int CompileShader(unsigned int type, std::string& source);

	unsigned int CreateShader(std::string& vertexShader, std::string& fragmentShader);

public:

	Shader(const std::string& file_path);

	static void useShader();

	static void setColor(float red, float green, float blue, float alpha);

	static void deleteShader();
};