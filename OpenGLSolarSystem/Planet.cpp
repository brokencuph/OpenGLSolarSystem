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
	textureValid = true;
	return textureObject = Utils::loadTexture(texturePath.c_str());
}

glm::mat4 Planet::getScaleMatrix()
{
	return glm::scale(glm::mat4(1.0f), { scale, scale, scale });
}

glm::mat4 Planet::getTranslationMatrix(float time)
{
	return glm::translate(glm::mat4(1.0f),
		{ trackRadius * sin(initialPhase + omega * time),
		0,
		trackRadius * cos(initialPhase + omega * time) });
}

Planet::Planet() : trackRadius(0.0f), scale(1.0f), period(1.0f), selfPeriod(1.0f),
	initialPhase(0.0f), texturePath(), omega(6.28f), selfAxis(0.0f, 1.0f, 0.0f)
{

}

glm::mat4 Planet::getRotationMatrix(float time)
{
	return glm::rotate(glm::mat4(1.0f), -time / selfPeriod * 6.28f, selfAxis);
}

Planet::Planet(float _trackRadius,
	float _scale,
	float _period,
	float _selfPeriod,
	float _initialPhase,
	std::string _texturePath) :
	trackRadius(_trackRadius),
	scale(_scale),
	period(_period),
	selfPeriod(_selfPeriod),
	initialPhase(_initialPhase),
	texturePath(std::move(_texturePath)),
	omega(6.28f / _period),
	selfAxis(0.0f, 1.0f, 0.0f)
{

}