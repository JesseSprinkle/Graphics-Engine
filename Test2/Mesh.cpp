#include "Mesh.h"

Mesh::Mesh(GLfloat* _vertices, GLuint _vertexCount) :
	vertices(_vertices), vertexCount(_vertexCount), vertexNormals(nullptr), textureCoordinates(nullptr)
{
	glGenVertexArrays(1, &vaoID);
	glGenBuffers(1, &vboID);
	glBindVertexArray(vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	// allocate memory
	glBufferData(GL_ARRAY_BUFFER, vertexCount * 3LL * sizeof(GLfloat), 0, GL_STATIC_DRAW);

	// load vertices
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertexCount * 3LL * sizeof(GLfloat), vertices);

	// tell opengl how attributes are formatted, enable attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	hasNormals = false;
	hasTexCoords = false;
}

Mesh::Mesh(GLfloat* _vertices, GLuint _vertexCount, GLfloat* _vertexNormals, GLfloat* _textureCoordinates) : 
	vertices(_vertices), vertexCount(_vertexCount), vertexNormals(_vertexNormals), textureCoordinates(_textureCoordinates)
{
	glGenVertexArrays(1, &vaoID);
	glGenBuffers(1, &vboID);
	glBindVertexArray(vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	// allocate memory
	glBufferData(GL_ARRAY_BUFFER, vertexCount * 8LL * sizeof(GLfloat), 0, GL_STATIC_DRAW);
	
	// load vertices, normals, and texture coords. not interweaving
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertexCount * 3LL * sizeof(GLfloat), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, vertexCount * 3LL * sizeof(GLfloat), vertexCount * 3LL * sizeof(GLfloat), vertexNormals);
	glBufferSubData(GL_ARRAY_BUFFER, vertexCount * 6LL * sizeof(GLfloat), vertexCount * 2LL * sizeof(GLfloat), textureCoordinates);
	
	// tell opengl how attributes are formatted, enable attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)(vertexCount * 3LL * sizeof(GLfloat)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)(vertexCount * 6LL * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	hasNormals = true;
	hasTexCoords = true;
}

void Mesh::loadVAO()
{
	glBindVertexArray(vaoID);
}

void Mesh::draw()
{
	loadVAO();
	glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}

bool Mesh::hasTextureCoordinates()
{
	return hasTexCoords;
}

bool Mesh::hasNormalCoordinates()
{
	return hasNormals;
}