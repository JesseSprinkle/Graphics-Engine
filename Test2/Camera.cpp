#include "Camera.h"

Camera::Camera()
{
	lookVec = glm::vec3(0, 0, -1);
	cameraPos = glm::vec3(0, 0, 0);
	upVec = glm::vec3(0, 1, 0);
	dirty = false;
	viewMatrix = glm::lookAt(cameraPos, cameraPos + lookVec, upVec);
}

void Camera::setPosition(glm::vec3 _position)
{
	cameraPos = _position;
	dirty = true;
}
void Camera::setLookVector(glm::vec3 _lookVec)
{
	lookVec = _lookVec;
	dirty = true;
}

glm::mat4 Camera::getViewMatrix()
{
	if (dirty)
	{
		dirty = false;
		return glm::lookAt(cameraPos, cameraPos + lookVec, upVec);
	}
	return viewMatrix;
}
