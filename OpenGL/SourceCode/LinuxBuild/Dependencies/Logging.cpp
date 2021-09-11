#include "Logging.h"
#include <iostream>
#include <GL/glew.h>

// define logging level 0 = LOW 1 = NORMAL 2 = HIGH
int lvl = 0;

void print(string message)
{
	cout << message << endl;
}

void info(string message)
{
	if (lvl == 0)
	{
		cout << "\033[1;34m" << "[INFO!]: " << message << "\033[0m" << endl;
	}
}

void warn(string message)
{
	if (lvl != 2)
	{
		cout << "\033[1;33m" << "[WARNING!]: " << message << "\033[0m" << endl;
	}
}

void error(string message)
{
	cout << "\033[1;31m" << "[ERROR!]: " << message << "\033[0m" << endl;
}

void glError(const char* er, int line, const char* file)
{
	if (GLenum err = glGetError() != GL_NO_ERROR)
	{
		error(to_string(err) + "    " + er + "    in Line: " + to_string(line) + "    in Line: " + file);
		exit(-1);
	}
}

void set_Level(int Level)
{
	if (-1 < Level || Level < 3)
	{
		lvl = Level;
	}
	else
	{
		lvl = 0;
	}
}
