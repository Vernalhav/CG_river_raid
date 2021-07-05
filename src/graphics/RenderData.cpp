#include "RenderData.h"

RenderData::RenderData() : vaoId(-1), vboId(-1), eboId(-1), materialPath(""), texture() { }
RenderData::RenderData(const std::string& texturePath)
	: vaoId(-1), vboId(-1), eboId(-1), materialPath(""), texture(texturePath) { }

RenderData::~RenderData() {
	glDeleteBuffers(1, (const GLuint*)&vboId);
	glDeleteBuffers(1, (const GLuint*)&eboId);
}
