#pragma once

#include <string>
#include "GL/glew.h"
#include "Utils.h"

// holds specific data for a planet
// does not hold the Sphere object
struct Planet
{
private:
	bool textureValid = false;
	GLuint textureObject;
	float omega;
public:
	float trackRadius;
	float scale;
	float period;
	float initialPhase;
	std::string texturePath;

	GLuint getTextureObject();

	glm::mat4 getScaleMatrix();

	glm::mat4 getTranslationMatrix(float time);

	Planet();

	Planet(float _trackRadius,
		float _scale,
		float _period,
		float _initialPhase,
		std::string _texturePath);
};