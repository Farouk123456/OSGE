#include "VertexArray.h"
#include <GL/glew.h>

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &vaoID);
}

void VertexArray::bind()
{
	glBindVertexArray(vaoID);
}

void VertexArray::unbind()
{
	glBindVertexArray(0);
}

unsigned int VertexArray::get_ID()
{
	return vaoID;
}