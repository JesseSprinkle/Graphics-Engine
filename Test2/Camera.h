#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Camera
{
private:
	bool dirty;
	glm::vec3 cameraPos;
	glm::vec3 lookVec;
	glm::vec3 upVec;
	glm::mat4 viewMatrix;
public:
	Camera();
	void setPosition(glm::vec3 _position);
	void setLookVector(glm::vec3 _lookVec);
	glm::mat4 getViewMatrix();
};