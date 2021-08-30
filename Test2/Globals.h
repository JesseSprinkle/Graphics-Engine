#pragma once
#include <memory>
#include <glm/glm.hpp>
#include "Camera.h"

std::shared_ptr<Camera> g_Camera;
glm::mat4 g_projectionMatrix;