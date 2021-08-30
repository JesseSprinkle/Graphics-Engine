#pragma once
#include <GL/glew.h>
class Mesh
{
private:
	GLfloat* vertices;
	GLuint vertexCount;
	GLfloat* vertexNormals;
	GLfloat* textureCoordinates;
	GLuint vaoID, vboID;
	bool hasTexCoords, hasNormals;
public:
	Mesh(GLfloat* _vertices, GLuint _vertexCount);
	Mesh(GLfloat* _vertices, GLuint _vertexCount, GLfloat* _vertexNormals, GLfloat* _textureCoordinates);
	bool hasTextureCoordinates();
	bool hasNormalCoordinates();
	void loadVAO();
	void draw();
};