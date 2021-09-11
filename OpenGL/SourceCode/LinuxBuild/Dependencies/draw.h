#pragma once
#include <iostream>
#include <vector>
#include "Shader.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "Logging.h"
#include "tools.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <array>
#include <cmath>

void line(Shader shader, double Ax, double Ay, double Bx, double By, array <float, 4> color);

void ellipse(Shader shader, double x, double y, double rx, double ry, array <float, 4> color, bool fill);

void triangle(Shader shader, double Ax, double Ay, double Bx, double By, double Cx, double Cy, array <float, 4> color, bool fill);

void rectangle(Shader shader, double x, double y, double width, double height, array <float, 4> color, bool fill);

void pentagon(Shader shader, double x, double y, double rx, double ry, array <float, 4> color, bool fill);

void hexagon(Shader shader, double x, double y, double rx, double ry, array <float, 4> color, bool fill);

void grid(Shader shader, double x, double y, double width, double height, double line_width, double columns, double rows, std::array <float, 4> color);

void loading_bar(Shader shader, double x, double y, double width, double height, double border_line_width, double val, double min_val, double max_val, std::array <float, 4> border_color);

bool button(Shader shader, double mouse_x, double mouse_y, double mouse_state, double mouse_button, double x, double y, double width, double height, std::string name, std::array <float, 4> color, bool fill, bool rounded, float roundnesss);

void bezier(Shader shader, array <double, 2> P0, array <double, 2> P1, array <double, 2> P2, array <double, 2> P3, array <float, 4> color);

void frame(Shader shader, double x, double y, double outside_width, double outside_height, double inside_height, double inside_width, std::array <float, 4> color);

void part_circle(Shader shader, double x, double y, double rx, double ry, std::array <float, 4> color, bool fill, float percent, float rotation);

void polygon(Shader shader, std::vector <std::array <float, 2>> vertexes, std::array <float, 4> color, bool fill);

void sinewave(Shader shader, float x, float y, float amplitude, float width, float frequency,float phase_shift, std::array <float, 4> color, float line_width);

void sinewave_sums(Shader shader, float x, float y, float width, float Sin1_amplitude, float Sin2_amplitude, float Sin1_frequency, float Sin2_frequency, float Sin1_phase_shift, float Sin2_phase_shift, std::array <float, 4> color, float line_width);

class Slider
{
    private:
        float x;
        float y;
        std::array <float, 4> line_col;
        std::array <float, 4> circle_col;
        float width;
        float height;
        float min_val;
        float max_val;
        float val;
        std::array <float, 2> circle_pos;

    public:
        Slider(float slider_x, float slider_y, std::array <float, 4> slider_line_col, std::array <float, 4> slider_circle_col, float slider_width, float slider_height, float slider_min_val, float slider_max_val, float slider_val);

        void draw(GLFWwindow* window, Shader shader, int window_height, int window_width);

        void changeParam(float new_x, float new_y, std::array <float, 4> new_slider_line_col, std::array <float, 4> new_slider_circle_col, float new_width, float new_height, float new_min_val, float new_max_val, float new_val); 

        float get_Value();

        void set_Value(float val);
};

void rounded_rectangle(Shader shader, double x, double y, double width, double height, array <float, 4> color, float roundness, bool fill);