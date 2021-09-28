#include "buffers.hpp"
#include "backends/opengl/buffers.hpp"

namespace Geg {
	RendererAPI::API RendererAPI::i_API = RendererAPI::API::OpenGL;

	VertexBuffer *VertexBuffer::create(float *vertices, unsigned int size) {
		switch (RendererAPI::getApi()) {
			case RendererAPI::API::OpenGL :
				return new GLVertexBuffer(vertices, size);
			case RendererAPI::API::Vulkan :
				GEG_ERROR("Vulkan not supported atm");
			default :
				GEG_ERROR("you must use renderer api");
		}
	}

	IndexBuffer *IndexBuffer::create(unsigned int *indices, unsigned int size) {
		switch (RendererAPI::getApi()) {
			case RendererAPI::API::OpenGL :
				return new GLIndexBuffer(indices, size);
			case RendererAPI::API::Vulkan :
				GEG_ERROR("Vulkan not supported atm");
			default :
				GEG_ERROR("you must use renderer api");
		}
	}

	void BufferLayout::add(ShaderDataType dataType, bool normlized) {
		elements.emplace_back(dataType, normlized);
		stride += ShaderDataTypeSize(dataType);
	}
}