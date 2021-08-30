#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <map>
#include <memory>
#include "Material.h"
#include "Mesh.h"
#include "Texture.h"
#include "ShaderProgram.h"
#define MAX_RENDERABLES_PER_SHADER 1024
class Renderable
{
private:
	ShaderProgramType programType;
	void addToRenderables();
	void removeFromRenderables();
	void setProgramType(ShaderProgramType t);
protected:
	static std::map<ShaderProgramType, Renderable**> renderables;
	unsigned int renderablesIndex = -1;
	std::shared_ptr<Material> material;
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Texture> texture;
public:
	~Renderable();
	std::shared_ptr<Mesh> getMesh();
	std::shared_ptr<Material> getMaterial();
	void attachTexture(std::shared_ptr<Texture> _texture);
	static Renderable** getRenderablesForShaderProgram(ShaderProgramType progType);
	virtual void draw(GLuint shaderProgramId) = 0;
	ShaderProgramType getProgramType();
};