#include "WorldRenderable.h"
#include <iostream>
WorldRenderable::WorldRenderable(std::shared_ptr<Mesh> _mesh, std::shared_ptr<Material> _material)
{
	mesh = _mesh;
	material = _material;
	programType = determineShaderProgramType();
	addToRenderables();
}

ShaderProgramType WorldRenderable::determineShaderProgramType()
{
	ShaderProgramType progType = ShaderProgramType::WORLD;
	if (mesh->hasNormalCoordinates())
	{
		progType |= ShaderProgramType::VERTEX_NORMALS;
	}

	if (mesh->hasTextureCoordinates())
	{
		progType = progType | ShaderProgramType::TEXTURED;
	}

	return progType;
}

void WorldRenderable::draw(GLuint shaderProgramId)
{
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramId, "MVP"), 1, GL_FALSE, glm::value_ptr(material->MVP));
	if ((programType & ShaderProgramType::TEXTURED) == ShaderProgramType::TEXTURED)
	{
		glBindTexture(GL_TEXTURE_2D, texture->getTextureID());
	}
	mesh->draw();
}