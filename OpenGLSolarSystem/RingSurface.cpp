#include <cmath>
#include <vector>
#include <iostream>
#include <glm/glm.hpp>
#include "RingSurface.h"
using namespace std;

RingSurface::RingSurface() {
	prec = 48;
	inner = 0.5f;
	outer = 0.2f;
	init();
}

RingSurface::RingSurface(float inner, float outer, int prec) : inner(inner), outer(outer), prec(prec) {
	init();
}

float RingSurface::toRadians(float degrees) { return (degrees * 2.0f * 3.14159f) / 360.0f; }

void RingSurface::init() {
	numVertices = (prec + 1) + (prec + 1);
	numIndices = prec * 6;
	for (int i = 0; i < numVertices; i++) { vertices.push_back(glm::vec3()); }
	for (int i = 0; i < numVertices; i++) { texCoords.push_back(glm::vec2()); }
	for (int i = 0; i < numVertices; i++) { normals.push_back(glm::vec3()); }
	//for (int i = 0; i < numVertices; i++) { tangents.push_back(glm::vec3()); }
	for (int i = 0; i < numIndices; i++) { indices.push_back(0); }

	// calculate triangle vertices

	for (int i = 0; i <= prec; i++)
	{
		float xi = -(float)(inner * cos(toRadians(i * 360.0f / prec)));
		float zi = (float)(inner * sin(toRadians(i * 360.0f / prec)));
		float xo = -(float)((inner + outer) * cos(toRadians(i * 360.0f / prec)));
		float zo = (float)((inner + outer) * sin(toRadians(i * 360.0f / prec)));
		vertices[2 * i] = glm::vec3(xi, 0, zi);
		vertices[2 * i + 1] = glm::vec3(xo, 0, zo);
		texCoords[2 * i] = glm::vec2((float)i / prec, 0.0f);
		texCoords[2 * i + 1] = glm::vec2((float)i / prec, 1.0f);
		normals[2 * i] = normals[2 * i + 1] = glm::vec3(0.0f, -1.0f, 0.0f);
		// tangents not needed, so omitted
	}
	// calculate triangle indices
	for (int i = 0; i<prec; i++) {
		indices[6 * i + 0] = 2 * i;
		indices[6 * i + 1] = 2 * i + 1;
		indices[6 * i + 2] = 2 * (i + 1) + 1;
		indices[6 * i + 3] = 2 * i;
		indices[6 * i + 4] = 2 * (i + 1) + 1;
		indices[6 * i + 5] = 2 * (i + 1);
	}
}

int RingSurface::getNumVertices() { return numVertices; }
int RingSurface::getNumIndices() { return numIndices; }
std::vector<int> RingSurface::getIndices() { return indices; }
std::vector<glm::vec3> RingSurface::getVertices() { return vertices; }
std::vector<glm::vec2> RingSurface::getTexCoords() { return texCoords; }
std::vector<glm::vec3> RingSurface::getNormals() { return normals; }
std::vector<glm::vec3> RingSurface::getTangents() { throw std::exception(); }