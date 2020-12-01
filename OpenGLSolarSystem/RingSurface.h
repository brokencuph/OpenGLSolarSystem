#include <cmath>
#include <vector>
#include <glm\glm.hpp>
class RingSurface
{
private:
	int numVertices;
	int numIndices;
	std::vector<int> indices;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> tangents;
	int prec;
	float inner;
	float outer;
	void init();
	float toRadians(float degrees);

public:
	RingSurface();
	RingSurface(float inner, float outer, int prec);
	int getNumVertices();
	int getNumIndices();
	std::vector<int> getIndices();
	std::vector<glm::vec3> getVertices();
	std::vector<glm::vec2> getTexCoords();
	std::vector<glm::vec3> getNormals();
	std::vector<glm::vec3> getTangents();
};