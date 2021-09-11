#pragma once

// class for creating buffers
class VertexBuffer
{
	private:
		unsigned int BufferID;
		int data_size;

	public:
		VertexBuffer();

		~VertexBuffer();

		void write(float data[], int size_of_data);

		void bind();

		void unbind();

		unsigned int get_ID();
};