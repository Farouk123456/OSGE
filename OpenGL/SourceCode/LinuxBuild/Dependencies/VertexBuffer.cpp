#include "VertexBuffer.h"
#include <GL/glew.h>

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &BufferID);
	glBindBuffer(GL_ARRAY_BUFFER, BufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(int), 0, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &BufferID);
}

void VertexBuffer::write(float data[], int size_of_data)
{
	data_size = size_of_data;
	glBufferData(GL_ARRAY_BUFFER, size_of_data, data, GL_DYNAMIC_DRAW);
}

void VertexBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, BufferID);

}

void VertexBuffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

unsigned int VertexBuffer::get_ID()
{
	return BufferID;
}