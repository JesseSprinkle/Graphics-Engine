#pragma once
#include <memory>
#include "VertexShader.h"
#include "FragmentShader.h"

// shader program types. can combine types for different configurations, for example WORLD | TEXTURED determines what shader program will be used
enum class ShaderProgramType : unsigned
{
	WORLD = 1u,
	UI = 1u << 1,
	VERTEX_NORMALS = 1u << 2,
	TEXTURED = 1u << 3,
};

inline ShaderProgramType& operator|=(ShaderProgramType& a, ShaderProgramType b)
{
	return a = static_cast<ShaderProgramType>((unsigned)a | (unsigned)b);
}

inline ShaderProgramType& operator&=(ShaderProgramType& a, ShaderProgramType b)
{
	return a = static_cast<ShaderProgramType>((unsigned)a & (unsigned)b);
}

inline constexpr ShaderProgramType operator|(ShaderProgramType a, ShaderProgramType b)
{
	return static_cast<ShaderProgramType>((unsigned)a | (unsigned)b);
}

inline constexpr ShaderProgramType operator&(ShaderProgramType a, ShaderProgramType b)
{
	return static_cast<ShaderProgramType>((unsigned)a & (unsigned)b);
}


class ShaderProgram
{
private:
	GLuint progId;
public:
	ShaderProgram(std::shared_ptr<VertexShader> _vertexShader, std::shared_ptr<FragmentShader> _fragmentShader);
	~ShaderProgram();
	GLuint getProgramId();
	void use();
};