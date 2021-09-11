#include "draw.h"


void ellipse(Shader shader, double x, double y, double rx, double ry, std::array <float, 4> color, bool fill)
{
	VertexBuffer VBuff;
	VertexArray vertexArray;

	float vertexes[700];

	int i = 0;
	double a = 0;

	while (a < pi * 2)
	{
		if ((i % 2) == 0) { vertexes[i] = cos(a) * rx + x; }

		else { vertexes[i] = sin(a) * ry + y; }

		a += 0.01;
		i += 1;
	}

	//writing a vertex array to our vertex buffer
	VBuff.write(vertexes, sizeof(vertexes));

	shader.setColor(color[0], color[1], color[2], color[3]);

	// bind buffers, ...
	VBuff.bind();
	vertexArray.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	if (fill) { glDrawArrays(GL_POLYGON, 0, i / 2); }

	else { glDrawArrays(GL_LINE_LOOP, 0, i / 2); }

	// unbind buffers, ...
	VBuff.unbind();
	vertexArray.unbind();

	VBuff.~VertexBuffer();
	vertexArray.~VertexArray();

}

void line(Shader shader, double Ax, double Ay, double Bx, double By, std::array <float, 4> color)
{
	//creating a vertex buffer object
	VertexBuffer VBuff;
	VertexArray vertexArray;

	//creating a vertex array
	float vertices[] = {
		Ax, Ay,
		Bx, By
	};

	//writing a vertex array to our vertex buffer
	VBuff.write(vertices, sizeof(vertices));

	shader.setColor(color[0], color[1], color[2], color[3]);

	// bind buffers, ...
	VBuff.bind();
	vertexArray.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glDrawArrays(GL_LINES, 0, sizeof(vertices) / 4 / 2);

	// unbind buffers, ...
	VBuff.unbind();
	vertexArray.unbind();

	VBuff.~VertexBuffer();
	vertexArray.~VertexArray();
}

void triangle(Shader shader, double Ax, double Ay, double Bx, double By, double Cx, double Cy, std:: array <float, 4> color, bool fill)
{
	VertexBuffer VBuff;
	VertexArray vertexArray;

	float vertices[] = {
		Ax, Ay,
		Bx, By,
		Cx, Cy
	};

	//writing a vertex array to our vertex buffer
	VBuff.write(vertices, sizeof(vertices));

	shader.setColor(color[0], color[1], color[2], color[3]);

	// bind buffers, ...
	VBuff.bind();
	vertexArray.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	if (fill) { glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / 4 / 2); }

	else { glDrawArrays(GL_LINE_LOOP, 0, sizeof(vertices) / 4 / 2); }

	// unbind buffers, ...
	VBuff.unbind();
	vertexArray.unbind();

	VBuff.~VertexBuffer();
	vertexArray.~VertexArray();
}

void rectangle(Shader shader, double x, double y, double width, double height, std::array <float, 4> color, bool fill)
{
	//creating a vertex buffer object
	VertexBuffer VBuff;
	VertexArray vertexArray;

	//creating a vertex array
	float vertices[] = {
		x + width / 2, y + height / 2,
		x + width / 2, y - height / 2,
		x - width / 2, y - height / 2,
		x - width / 2, y + height / 2
	};

	//writing a vertex array to our vertex buffer
	VBuff.write(vertices, sizeof(vertices));

	shader.setColor(color[0], color[1], color[2], color[3]);

	// bind buffers, ...
	VBuff.bind();
	vertexArray.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	if (fill) { glDrawArrays(GL_POLYGON, 0, sizeof(vertices) / 4 / 2); }

	else { glDrawArrays(GL_LINE_LOOP, 0, sizeof(vertices) / 4 / 2); }

	// unbind buffers, ...
	VBuff.unbind();
	vertexArray.unbind();

	VBuff.~VertexBuffer();
	vertexArray.~VertexArray();
}

void rounded_rectangle(Shader shader, double x, double y, double width, double height, array <float, 4> color, float roundness, bool fill)
{
	float r = map(0, height / 2, 0, 100, roundness);

	if(fill)
	{
		rectangle(shader, x, y, width, height - r*2, color, fill);
		rectangle(shader, x, y, width - r*2, height, color, fill);
		part_circle(shader, x + width / 2 - r - 0.001, y + height / 2 - r, r, r, color, fill, 0.25, 0);
		part_circle(shader, x - width / 2 + r, y + height / 2 - r, r, r, color, fill, 0.25, 90);
		part_circle(shader, x - width / 2 + r, y - height / 2 + r, r, r, color, fill, 0.25, 180);
		part_circle(shader, x + width / 2 - r, y - height / 2 + r, r, r, color, fill, 0.25, 270);
	}
	else
	{
		line(shader, x - width / 2 + r, y + height / 2, x + width / 2 - r, y + height / 2, color);
		line(shader, x - width / 2 + r, y - height / 2, x + width / 2 - r, y - height / 2, color);
		line(shader, x - width / 2, y - height / 2 + r, x - width / 2, y + height / 2 - r, color);
		line(shader, x + width / 2, y - height / 2 + r, x + width / 2, y + height / 2 - r, color);

		part_circle(shader, x + width / 2 - r - 0.002, y + height / 2 - r, r, r, color, fill, 0.25, 0);
		part_circle(shader, x - width / 2 + r, y + height / 2 - r, r, r, color, fill, 0.25, 90);
		part_circle(shader, x - width / 2 + r, y - height / 2 + r, r, r, color, fill, 0.25, 180);
		part_circle(shader, x + width / 2 - r, y - height / 2 + r, r, r, color, fill, 0.25, 270);
	}
}

void pentagon(Shader shader, double x, double y, double rx, double ry, std::array <float, 4> color, bool fill)
{
	VertexBuffer VBuff;
	VertexArray vertexArray;

	float vertexes[10] = {
		cos(pi * 2 / 5 + 1.5708) * rx + x, sin(pi * 2 / 5 + 1.5708) * ry + y,
		cos(pi * 2 / 5 * 2 + 1.5708) * rx + x, sin(pi * 2 / 5 * 2 + 1.5708) * ry + y,
		cos(pi * 2 / 5 * 3 + 1.5708) * rx + x, sin(pi * 2 / 5 * 3 + 1.5708) * ry + y,
		cos(pi * 2 / 5 * 4 + 1.5708) * rx + x, sin(pi * 2 / 5 * 4 + 1.5708) * ry + y,
		cos(pi * 2 + 1.5708) * rx + x, sin(pi * 2 + 1.5708) * ry + y
	};


	//writing a vertex array to our vertex buffer
	VBuff.write(vertexes, sizeof(vertexes));

	shader.setColor(color[0], color[1], color[2], color[3]);

	// bind buffers, ...
	VBuff.bind();
	vertexArray.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	if (fill) { glDrawArrays(GL_POLYGON, 0, sizeof(vertexes) / 4 / 2); }

	else { glDrawArrays(GL_LINE_LOOP, 0, sizeof(vertexes) / 4 / 2); }

	// unbind buffers, ...
	VBuff.unbind();
	vertexArray.unbind();

	VBuff.~VertexBuffer();
	vertexArray.~VertexArray();
}

void hexagon(Shader shader, double x, double y, double rx, double ry, std::array <float, 4> color, bool fill)
{
	VertexBuffer VBuff;
	VertexArray vertexArray;

	float vertexes[12] = {
		cos(pi * 2 / 6 + 1.5708) * rx + x, sin(pi * 2 / 6 + 1.5708) * ry + y,
		cos(pi * 2 / 6 * 2 + 1.5708) * rx + x, sin(pi * 2 / 6 * 2 + 1.5708) * ry + y,
		cos(pi * 2 / 6 * 3 + 1.5708) * rx + x, sin(pi * 2 / 6 * 3 + 1.5708) * ry + y,
		cos(pi * 2 / 6 * 4 + 1.5708) * rx + x, sin(pi * 2 / 6 * 4 + 1.5708) * ry + y,
		cos(pi * 2 / 6 * 5 + 1.5708) * rx + x, sin(pi * 2 / 6 * 5 + 1.5708) * ry + y,
		cos(pi * 2 + 1.5708) * rx + x, sin(pi * 2 + 1.5708) * ry + y,
	};

	//writing a vertex array to our vertex buffer
	VBuff.write(vertexes, sizeof(vertexes));

	shader.setColor(color[0], color[1], color[2], color[3]);

	// bind buffers, ...
	VBuff.bind();
	vertexArray.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	if (fill) { glDrawArrays(GL_POLYGON, 0, sizeof(vertexes) / 4 / 2); }

	else { glDrawArrays(GL_LINE_LOOP, 0, sizeof(vertexes) / 4 / 2); }

	// unbind buffers, ...
	VBuff.unbind();
	vertexArray.unbind();

	VBuff.~VertexBuffer();
	vertexArray.~VertexArray();
}

void polygon(Shader shader, std::vector <std::array <float, 2> > vertexes, std::array <float, 4> color, bool fill)
{
	std::vector <float> vertices;

	for (int i = 0; i < vertexes.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			vertices.push_back(vertexes[i][j]);
		}
	}


	VertexBuffer VBuff;
	VertexArray vertexArray;

	VBuff.write(vertices.data(), vertices.size() * sizeof(float));

	shader.setColor(1.0f, 0.0f, 0.0f, 1.0f);

	VBuff.bind();
	vertexArray.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glDrawArrays(GL_POLYGON, 0, vertices.size());

	VBuff.unbind();
	vertexArray.unbind();
}

void frame(Shader shader, double x, double y, double outside_width, double outside_height, double inside_height, double inside_width, std::array <float, 4> color)
{
	//creating a vertex buffer object
	VertexBuffer VBuff1;
	VertexArray vertexArray1;

	//creating a vertex array
	float part1[] = {
		x - inside_width / 2, y + inside_height / 2,
		x - outside_width / 2, y + outside_height / 2,
		x + outside_width / 2, y + outside_height / 2,
		x + inside_width / 2, y + inside_height / 2,
	};

	//writing a vertex array to our vertex buffer
	VBuff1.write(part1, sizeof(part1));

	shader.setColor(color[0], color[1], color[2], color[3]);

	// bind buffers, ...
	VBuff1.bind();
	vertexArray1.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glDrawArrays(GL_POLYGON, 0, sizeof(part1) / 4 / 2);

	// unbind buffers, ...
	VBuff1.unbind();
	vertexArray1.unbind();

	VBuff1.~VertexBuffer();
	vertexArray1.~VertexArray();

	//creating a vertex buffer object
	VertexBuffer VBuff2;
	VertexArray vertexArray2;

	//creating a vertex array
	float part2[] = {
		x - inside_width / 2, y + inside_height / 2,
		x - outside_width / 2, y + outside_height / 2,
		x - outside_width / 2, y - outside_height / 2,
		x - inside_width / 2, y - inside_height / 2,
	};

	//writing a vertex array to our vertex buffer
	VBuff1.write(part2, sizeof(part2));

	shader.setColor(color[0], color[1], color[2], color[3]);

	// bind buffers, ...
	VBuff2.bind();
	vertexArray2.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glDrawArrays(GL_POLYGON, 0, sizeof(part2) / 4 / 2);

	// unbind buffers, ...
	VBuff2.unbind();
	vertexArray2.unbind();

	VBuff2.~VertexBuffer();
	vertexArray2.~VertexArray();

	//creating a vertex buffer object
	VertexBuffer VBuff3;
	VertexArray vertexArray3;

	//creating a vertex array
	float part3[] = {
		x - inside_width / 2, y - inside_height / 2,
		x - outside_width / 2, y - outside_height / 2,
		x + outside_width / 2, y - outside_height / 2,
		x + inside_width / 2, y - inside_height / 2,
	};

	//writing a vertex array to our vertex buffer
	VBuff1.write(part3, sizeof(part3));

	shader.setColor(color[0], color[1], color[2], color[3]);

	// bind buffers, ...
	VBuff3.bind();
	vertexArray3.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glDrawArrays(GL_POLYGON, 0, sizeof(part3) / 4 / 2);

	// unbind buffers, ...
	VBuff3.unbind();
	vertexArray3.unbind();

	VBuff3.~VertexBuffer();
	vertexArray3.~VertexArray();

	//creating a vertex buffer object
	VertexBuffer VBuff4;
	VertexArray vertexArray4;

	//creating a vertex array
	float part4[] = {
		x + inside_width / 2, y - inside_height / 2,
		x + outside_width / 2, y - outside_height / 2,
		x + outside_width / 2, y + outside_height / 2,
		x + inside_width / 2, y + inside_height / 2,
	};

	//writing a vertex array to our vertex buffer
	VBuff1.write(part4, sizeof(part4));

	shader.setColor(color[0], color[1], color[2], color[3]);

	// bind buffers, ...
	VBuff4.bind();
	vertexArray4.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glDrawArrays(GL_POLYGON, 0, sizeof(part4) / 4 / 2);

	// unbind buffers, ...
	VBuff4.unbind();
	vertexArray4.unbind();

	VBuff4.~VertexBuffer();
	vertexArray4.~VertexArray();
}

void grid(Shader shader, double x, double y, double width, double height, double line_width, double columns, double rows, std::array <float, 4> color)
{
	frame(shader, x, y, width+line_width, height+line_width, height-line_width, width-line_width, color);

	for (double i = x - width /2; i < x + width / 2; i+=width/columns)
	{
		rectangle(shader, i, y, line_width, height, color, true);
	}

	for (double i = y - height / 2; i < y + height / 2; i+=height/rows)
	{
		rectangle(shader, x, i, width, line_width, color, true);
	}
}

// ability to name loading bar or show current value in decimal or percentage
void loading_bar(Shader shader, double x, double y, double width, double height, double border_line_width, double val, double min_val, double max_val, std::array <float, 4> border_color)
{
	rectangle(shader, x, y, width + border_line_width, height + border_line_width, border_color, true);
	rectangle(shader, x, y, width, height, {1, 0.25, 0.125, 1}, true);
	
	//creating a vertex buffer object
	VertexBuffer VBuff1;
	VertexArray vertexArray1;

	//creating a vertex array
	float part1[] = {
		x - width / 2, y - height / 2,
		(x - width /2) + map(0, width, min_val, max_val, val), y - height / 2,
		(x - width /2) + map(0, width, min_val, max_val, val), y + height / 2,
		x - width / 2, y = height / 2
	};

	//writing a vertex array to our vertex buffer
	VBuff1.write(part1, sizeof(part1));

	shader.setColor(0.14453, 1, 0.25, 1);

	// bind buffers, ...
	VBuff1.bind();
	vertexArray1.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glDrawArrays(GL_POLYGON, 0, sizeof(part1) / 4 / 2);

	// unbind buffers, ...
	VBuff1.unbind();
	vertexArray1.unbind();

	VBuff1.~VertexBuffer();
	vertexArray1.~VertexArray();
}

// ability to name button
bool button(Shader shader, double mouse_x, double mouse_y, double mouse_state, double mouse_button, double x, double y, double width, double height, std::string name, std::array <float, 4> color, bool fill, bool rounded, float roundnesss)
{	
	std::array <float, 4> col = {color[0] - 0.1, color[1] - 0.1, color[2] - 0.1, color[3]};

	if (!rounded)
	{
		if (mouse_state == GLFW_PRESS && mouse_button == GLFW_MOUSE_BUTTON_LEFT)
		{
			if (mouse_y < y + height / 2 && mouse_y > y - height / 2)
			{
				rectangle(shader, x, y, width, height, color, fill);

				if (mouse_x < x + width / 2 && mouse_x > x - width / 2)
				{
					rectangle(shader, x, y, width, height, col, fill);
					return true;
				}

				return false;
			}
			else
			{
				rectangle(shader, x, y, width, height, color, fill);
				return false;
			}
		}
		else
		{
			rectangle(shader, x, y, width, height, color, fill);
			return false;
		}
	}
	else
	{
		if (mouse_state == GLFW_PRESS && mouse_button == GLFW_MOUSE_BUTTON_LEFT)
		{
			if (mouse_y < y + height / 2 && mouse_y > y - height / 2)
			{
				rounded_rectangle(shader, x, y, width, height, color, roundnesss, fill);

				if (mouse_x < x + width / 2 && mouse_x > x - width / 2)
				{
					rounded_rectangle(shader, x, y, width, height, col, roundnesss, fill);
					return true;
				}

				return false;
			}
			else
			{
				rounded_rectangle(shader, x, y, width, height, color, roundnesss, fill);
				return false;
			}
		}
		else
		{
			rounded_rectangle(shader, x, y, width, height, color, roundnesss, fill);
			return false;
		}
	}
}

void bezier(Shader shader, array <double, 2> P0, array <double, 2> P1, array <double, 2> P2, array <double, 2> P3, array <float, 4> color)
{
	VertexBuffer VBuff;
	VertexArray vertexArray;

	float vertexes[700];

	int i = 0;
	double t = 0;

	while (t < 1.01)
	{
		double CX = pow((1 - t), 3) * P0[0] + 3 * pow((1 - t), 2) * t * P1[0] + 3 * (1 - t) * pow(t, 2) * P2[0] + pow(t, 3) * P3[0];
		double CY = pow((1 - t), 3) * P0[1] + 3 * pow((1 - t), 2) * t * P1[1] + 3 * (1 - t) * pow(t, 2) * P2[1] + pow(t, 3) * P3[1];

		vertexes[i] = CX;
		vertexes[i + 1] = CY;

		t += 0.01;
		i += 2;
	}

	VBuff.write(vertexes, sizeof(vertexes));


	VBuff.bind();
	vertexArray.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	shader.setColor(color[0], color[1], color[2], color[3]);

	glDrawArrays(GL_LINE_STRIP, 0, i / 2);

	VBuff.unbind();
	vertexArray.unbind();

	VBuff.~VertexBuffer();
	vertexArray.~VertexArray();
}

void part_circle(Shader shader, double x, double y, double rx, double ry, std::array <float, 4> color, bool fill, float percent, float rotation)
{
	VertexBuffer VBuff;
	VertexArray vertexArray;

	float vertexes[10000];
	int i;

	if (fill)
	{
		i = 2;

    	vertexes[0] = x;
		vertexes[1] = y;
	}
	else 
	{
		i = 0;
	}

    for (float a = deg_to_radian(rotation); a < pi*2*percent+deg_to_radian(rotation); a += (pi*2/10000))
    {
		if ((i % 2) == 0) { vertexes[i] = cos(a) * rx + x; }
    	else { vertexes[i] = sin(a) * ry + y; }
		i++;
	}

	VBuff.write(vertexes, sizeof(vertexes));

	shader.setColor(color[0], color[1], color[2], color[3]);

	VBuff.bind();
	vertexArray.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	if (fill) { glDrawArrays(GL_POLYGON, 0, i / 2); }

	else { glDrawArrays(GL_LINE_STRIP, 0, i / 2); }

	VBuff.unbind();
	vertexArray.unbind();

	VBuff.~VertexBuffer();
	vertexArray.~VertexArray();
}

void sinewave(Shader shader, float x, float y, float amplitude, float width, float frequency,float phase_shift, std::array <float, 4> color, float line_width)
{  
	VertexBuffer VBuff;
	VertexArray vertexArray;

	float vertexes[1000];
	int i = 0;

    glLineWidth(line_width);
        
    for (float a = 0; a < pi*2; a+=0.01)
    {
        float vertex[2] = {

            map( 0, width, 0, pi*2, a) + (x - width / 2),
                
            map(0, amplitude, -1, 1, sin( frequency*a + deg_to_radian(phase_shift) ) ) + (y - amplitude / 2)
        };

		if ((i % 2) == 0) { vertexes[i] = vertex[0]; }
    	else { vertexes[i] = vertex[1]; }
		i++;
    }
	
	VBuff.write(vertexes, sizeof(vertexes));

	shader.setColor(color[0], color[1], color[2], color[3]);

	VBuff.bind();
	vertexArray.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glDrawArrays(GL_LINE_STRIP, 0, i / 2);

	VBuff.unbind();
	vertexArray.unbind();

	VBuff.~VertexBuffer();
	vertexArray.~VertexArray();
}

void sinewave_sums(Shader shader, float x, float y, float width, float Sin1_amplitude, float Sin2_amplitude, float Sin1_frequency, float Sin2_frequency, float Sin1_phase_shift, float Sin2_phase_shift, std::array <float, 4> color, float line_width)
{
    VertexBuffer VBuff;
	VertexArray vertexArray;

	float vertexes[1000];
	int i = 0;

    glLineWidth(line_width);

    float amp_sum = Sin1_amplitude + Sin2_amplitude;

    for (float a = 0; a < pi*2; a+=0.01)
    {
        float vertex[2] = {

            map( 0, width, 0, pi*2, a) + (x - width / 2),

			map(y, y + amp_sum, -2, 2, (sin( Sin1_frequency * a + deg_to_radian(Sin1_phase_shift))) + (sin( Sin2_frequency * a + deg_to_radian(Sin2_phase_shift)))) + (y - amp_sum / 2)
		};	

        if ((i % 2) == 0) { vertexes[i] = vertex[0]; }
    	else { vertexes[i] = vertex[1]; }
		i++;
    }

	VBuff.write(vertexes, sizeof(vertexes));

	shader.setColor(color[0], color[1], color[2], color[3]);

	VBuff.bind();
	vertexArray.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glDrawArrays(GL_LINE_STRIP, 0, i / 2);

	VBuff.unbind();
	vertexArray.unbind();

	VBuff.~VertexBuffer();
	vertexArray.~VertexArray();
}

Slider::Slider(float slider_x, float slider_y, std::array <float, 4> slider_line_col, std::array <float, 4> slider_circle_col, float slider_width, float slider_height, float slider_min_val, float slider_max_val, float slider_val)
{
	x = slider_x; y = slider_y; width = slider_width; height = slider_height; line_col = slider_line_col; circle_col = slider_circle_col; min_val = slider_min_val; max_val = slider_max_val; val = slider_val;
	circle_pos[0] = x; circle_pos[1] = y;
}

void Slider::draw(GLFWwindow* window, Shader shader, int window_height, int window_width)
{
	double xpos, ypos;

	glfwGetCursorPos(window, &xpos, &ypos);

	xpos = map(-1, 1, 0, window_width, xpos) - 1;
	ypos = map(1, -1, 0, window_height, ypos) + 1;

	int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
	
	if (state == GLFW_PRESS)
	{
		if (xpos > x - width / 2 && xpos < x + width / 2)
		{
			if (ypos < y + height*2 && ypos > y - height*2)
			{
				val = map(min_val, max_val, x - width / 2, x + width / 2, xpos);
			}
		}
	}

	circle_pos[0] = map(0, x + width, min_val, max_val, val) - width / 2;
	glLineWidth(height*window_height);
	line(shader, x - width / 2 + height, y, x + width / 2 - height, y, line_col);

	part_circle(shader, x - width / 2 + height, y, height, height, line_col, true, 0.5, 90);
	part_circle(shader, x + width / 2 - height, y, height, height, line_col, true, 0.5, -90);

	ellipse(shader, circle_pos[0], circle_pos[1], height*2, height*2, circle_col, true);
}

void Slider::changeParam(float new_x, float new_y, std::array <float, 4> new_slider_line_col, std::array <float, 4> new_slider_circle_col, float new_width, float new_height, float new_min_val, float new_max_val, float new_val)
{
	x = new_x; y = new_y; width = new_width; height = new_height; line_col = new_slider_line_col; circle_col = new_slider_circle_col; min_val = new_min_val; max_val = new_max_val; val = new_val;
}

float Slider::get_Value() { return val; }

void Slider::set_Value(float new_val)
{
	if (new_val < min_val) { val = min_val; }

	else if (new_val > max_val) { val = max_val; }

	else { val = new_val; }
}
