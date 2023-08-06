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

private:
	//create memory arenas and request memory chunks from there.
	meshData vertices[4] = {
		//first triangle
		meshData(vec3(0.5f,0.5f,0.0f),vec2(1.0f,0.0f)),
		meshData(vec3(0.5f,-0.5f,0.0f),vec2(1.0f,1.0f)),
		meshData(vec3(-0.5f,-0.5f,0.0f),vec2(0.0f,1.0f)),
		meshData(vec3(-0.5f,0.5f,0.0f),vec2(0.0f,0.0f))

		//	meshData(vec3(0.5f,0.5f,0.0f),vec2(0.0f,0.0f)),
		//meshData(vec3(0.5f,-0.5f,0.0f),vec2(0.0f,1.0f)),
		//meshData(vec3(-0.5f,-0.5f,0.0f),vec2(1.0f,1.0f)),
		//meshData(vec3(-0.5f,0.5f,0.0f),vec2(1.0f,0.0f))

	};
	uivec3 indices[2]{
		uivec3(0,1,3),
		uivec3(1,2,3)
	};

	


	material Material;
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
	unsigned int texture;
};

