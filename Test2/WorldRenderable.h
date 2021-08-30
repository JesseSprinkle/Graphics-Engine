#pragma once
#include "Renderable.h"
class WorldRenderable : public Renderable
{
private:
	ShaderProgramType determineShaderProgramType();
public:
	WorldRenderable(std::shared_ptr<Mesh> _mesh, std::shared_ptr<Material> _material);
	void draw(GLuint shaderProgramId);
};