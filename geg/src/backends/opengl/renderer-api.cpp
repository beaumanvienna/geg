#include "renderer-api.hpp"

#include "glad/glad.h"

namespace Geg {
	void GLRendererAPI::clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void GLRendererAPI::clear(glm::vec4 color) {
		glClearColor(color.r, color.g, color.b, color.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void GLRendererAPI::drawIndexed(const std::shared_ptr<Pipeline>& vertexArray) {
		vertexArray->bind();
		vertexArray->getIndexBuffer()->bind();
		glDrawElements(GL_TRIANGLES, vertexArray->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);
	};
}		 // namespace Geg
