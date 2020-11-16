#include <string>
#include "GL/glew.h"
#include "Utils.h"
#include "Planet.h"
#include <cmath>

GLuint Planet::getTextureObject()
{
	if (textureValid)
	{
		return textureObject;
	}
	return Utils::loadTexture(texturePath.c_str());
}

constexpr glm::mat4 Planet::getScaleMatrix()
{
	return glm::scale(glm::mat4(1.0f), { scale, scale, scale });
}

constexpr glm::mat4 Planet::getTranslationMatrix(float time)
{
	return glm::translate(glm::mat4(1.0f),
		{ trackRadius * cos(initialPhase + omega * time),
		0,
		trackRadius * sin(initialPhase + omega * time) });
}

Planet::Planet() : trackRadius(0.0f), scale(1.0f), period(1.0f),
	initialPhase(0.0f), texturePath(), omega(6.28f)
{

}

Planet::Planet(float _trackRadius,
	float _scale,
	float _period,
	float _initialPhase,
	std::string _texturePath) :
	trackRadius(_trackRadius),
	scale(_scale),
	period(_period),
	initialPhase(_initialPhase),
	texturePath(std::move(_texturePath)),
	omega(6.28f / _period)
{

}