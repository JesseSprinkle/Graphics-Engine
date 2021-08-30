#pragma once
#include "Renderable.h"
class UIBase : Renderable
{
private:
	ShaderProgramType determineShaderProgramType();
public:
	UIBase(std::shared_ptr<Mesh> _mesh, std::shared_ptr<Material> _material);
	void draw(GLuint shaderProgramId);
};

