#include "dragoncore.h"
#include <iostream>
#include "Core/Rendering/Window.h"
#include "text.h"
#include <Core/Modules/IO/Logger.h>
#include <Core/Rendering/indexbycomponent.h>
#include "Main.h"
#include <stdlib.h>
#include <stdio.h>

void text::generateMesh()
{
	vec2 windowsize = CORE.Get().m_gameWindow.get()->windowsize;

	const char* text = "THIS IS A Long test 1245 TEDXT";

	float span = 2.0f / strlen(text);

	delete(vertices);
	delete(indices);

	vertices = new meshData[strlen(text) * 4];
	indices = new int[strlen(text) * 6];
	triangles = strlen(text) * 6;
	numindicies = strlen(text) * 6;
	numvert = strlen(text) * 4;

	float centerXPoint = 0;
	float halfspan = span * 0.5;

	float uvoffset = 1.0f / 16.0f;

	int localindex = 0;

	for (int i = 0; i < strlen(text); i++)
	{
		centerXPoint = 1 - (i * span + span / 2);
		centerXPoint = -centerXPoint;

		localindex = fontIndexHelper(text[i]);

		int uvx = localindex % 16;
		int uvy = floor(localindex / 16);

		vertices[i * 4 + 0] = meshData(
			vec3(centerXPoint - halfspan, +halfspan, 0),
			vec2(uvx * uvoffset + 0 * uvoffset, uvy * uvoffset + 0 * uvoffset));

		vertices[i * 4 + 1] = meshData(
			vec3(centerXPoint + halfspan, +halfspan, 0),
			vec2(uvx * uvoffset + 1 * uvoffset, uvy * uvoffset + 0 * uvoffset));

		vertices[i * 4 + 2] = meshData(
			vec3(centerXPoint - halfspan, -halfspan, 0),
			vec2(uvx * uvoffset + 0 * uvoffset, uvy * uvoffset + 1 * uvoffset));

		vertices[i * 4 + 3] = meshData(
			vec3(centerXPoint + halfspan, -halfspan, 0),
			vec2(uvx * uvoffset + 1 * uvoffset, uvy * uvoffset + 1 * uvoffset));

		indices[i * 6 + 0] = i * 4 + 0;
		indices[i * 6 + 1] = i * 4 + 1;
		indices[i * 6 + 2] = i * 4 + 2;
		indices[i * 6 + 3] = i * 4 + 2;
		indices[i * 6 + 4] = i * 4 + 1;
		indices[i * 6 + 5] = i * 4 + 3;
	}
}
