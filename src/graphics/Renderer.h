#pragma once

#include <gl/glew.h>
#include <glm/glm.hpp>
#include <vector>

#include "../engine/SceneObject.h"
#include "Shader.h"
#include "MeshLoader.h"

enum class PolygonMode;

class Renderer {
private:
	PolygonMode polygonMode;
	GLuint VAO;
	Shader shader;

public:
	Renderer(Shader s);
	~Renderer();

	void uploadMesh(RenderData* mesh);

	void drawObject(RenderData* object, const glm::mat4& mvp);

	void toggleDrawMode();
};