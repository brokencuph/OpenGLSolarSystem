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
	GLuint textureObject = 0u;
	float omega;
public:
	static float omegaScale;

	float trackRadius;
	float scale;
	float period;
	float selfPeriod;
	float initialPhase;
	std::string texturePath;
	glm::vec3 selfAxis;

	GLuint getTextureObject();

	glm::mat4 getScaleMatrix();

	glm::mat4 getTranslationMatrix(float time);

	glm::mat4 getRotationMatrix(float time);

	Planet();

	Planet(float _trackRadius,
		float _scale,
		float _period,
		float _selfPeriod,
		float _initialPhase,
		std::string _texturePath);
};