#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <array>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

#include "draw.h"
#include "tools.h"
#include "Shader.h"

void text(Shader shader, float x, float y, float size, std::array<float, 4> color);