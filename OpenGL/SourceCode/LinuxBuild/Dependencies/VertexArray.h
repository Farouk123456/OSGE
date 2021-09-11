#pragma once

// class for creating buffers
class VertexArray
{
private:
	unsigned int vaoID;

public:
	VertexArray();

	~VertexArray();

	void bind();

	void unbind();

	unsigned int get_ID();
};