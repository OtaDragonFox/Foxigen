#pragma once
#include "material.h"
#include "dragonmath.h"


struct colorMeshData
{
	vec3 vertexData = vec3(0,0,0);
	vec3 colorData = vec3(0, 0, 0);
	vec2 uvData = vec2(0, 0);
};
struct meshData
{
	vec3 vertexData = vec3(0, 0, 0);
	vec2 uvData = vec2(0, 0);
};


class mesh
{
public:
	void updateMesh();

	void renderMesh();
	virtual void generateMesh() {};

	//create memory arenas and request memory chunks from there.
	
	int numvert;
	meshData* vertices;

	int* indices;
	int numindicies;

	unsigned int triangles;
		
	material Material;
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
	unsigned int texture;
};

