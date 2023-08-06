#pragma once
#include "glm/glm.hpp"


#define vec2 glm::vec2
#define vec3 glm::vec3
#define vec4 glm::vec4

struct uivec3 {
	unsigned int x = 0;
	unsigned int y = 0;
	unsigned int z = 0;


	uivec3(int lx, int ly, int lz)
	{
		x = lx;
		y = ly;
		z = lz;
	}
};

