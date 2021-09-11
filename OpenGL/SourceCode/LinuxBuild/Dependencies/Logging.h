#pragma once
#include <cmath>

#define glCheckError(x)	x; glError(#x, __LINE__, __FILE__)
#include <string>

using namespace std;

// functions for logging and stuff
void print(string message);

void info(string message);

void warn(string message);

void error(string message);

void glError(const char* er, int line, const char* file);

void set_Level(int Level);
