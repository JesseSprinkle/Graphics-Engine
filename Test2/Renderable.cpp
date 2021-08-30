#include "Renderable.h"
#include <iostream>
std::map<ShaderProgramType, Renderable**> Renderable::renderables;


Renderable::~Renderable()
{
}

std::shared_ptr<Mesh> Renderable::getMesh()
{
	return mesh;
}

std::shared_ptr<Material> Renderable::getMaterial()
{
	return material;
}


void Renderable::attachTexture(std::shared_ptr<Texture> _texture)
{
	if ((programType & ShaderProgramType::TEXTURED) == ShaderProgramType::TEXTURED)
	{
		texture = _texture;
	}
	else
	{
		std::cout << "Error: could not attach texture to renderable that does not support textures" << std::endl;
	}
}

Renderable** Renderable::getRenderablesForShaderProgram(ShaderProgramType progType)
{
	return renderables[progType];
}

void Renderable::removeFromRenderables()
{
	if (renderablesIndex == -1)
	{
		std::cout << "Attempted to remove Renderable from renderables" << std::endl;
		exit(0);
	}
	renderables[programType][renderablesIndex] = nullptr;
	renderablesIndex = -1;
}


void Renderable::addToRenderables()
{
	if (renderablesIndex != -1)
	{
		std::cout << "Renderable already added to renderables" << std::endl;
		exit(0);
	}

	if (renderables.find(programType) == renderables.end())
	{
		renderables[programType] = new Renderable * [MAX_RENDERABLES_PER_SHADER];
		for (int i = 0; i < MAX_RENDERABLES_PER_SHADER; i++)
		{
			renderables[programType][i] = nullptr;
		}
	}

	for (int i = 0; i < MAX_RENDERABLES_PER_SHADER; i++)
	{
		if (renderables[programType][i] == nullptr)
		{
			renderablesIndex = i;
			renderables[programType][renderablesIndex] = this;
			break;
		}
	}
	if (renderablesIndex == -1)
	{
		std::cout << "Reached MAX_RENDERABLES_PER_SHADER, cannot allocate" << std::endl;
		exit(0);
	}
}



