#include "dragoncore.h"
#include "mesh.h"
#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include <Modules/IO/Logger.h>
#include "Main.h"
#include "ThirdParty/stb_image.h"
#include <Rendering/indexbycomponent.h>


void mesh::updateMesh()
{

	generateMesh();

	Material.compileShader("assets/defaultMaterial.vs", "assets/defaultMaterial.fs");
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, numindicies * sizeof(meshData), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numindicies*sizeof(int), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	int width, height, nrChannels;
	unsigned char* data = stbi_load("assets/Font.tga", &width, &height, &nrChannels, 0);
	if (data)
	{

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else 
	{
		LOG("Failed to load texture");
	}


	stbi_image_free(data);


	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);





	//shader stuff belongs into a material class of some sort. -> future ota stuff


}

void mesh::renderMesh()
{
	glUseProgram(Material.getMaterial());
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, triangles, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void mesh::generateMesh()
{
	vec2 windowsize = CORE.Get().m_gameWindow.get()->windowsize;

	const char* text = "THIS IS A Long test 1245 TEDXT";
	
	float span = 2.0f / strlen(text);
	std::cout << strlen(text);


	vertices = new meshData[strlen(text)*4];
	indices = new int[strlen(text)*6];

	triangles = strlen(text) * 6;
	std::cout << triangles << std::endl;;

	numindicies = strlen(text) * 6;
	numvert = strlen(text) * 4;

	float centerXPoint = 0;
	float halfspan = span / 2;
	int indexes[] = {
		40,37,44,44,47,55,47,50,44,36,1
	};
	float uvoffset = 1.0f/16.0f;
	
	int localindex = 0;

	for (int i = 0; i < strlen(text); i++)
	{
		centerXPoint = 1 - (i * span + span / 2);
		centerXPoint = -centerXPoint;

		LOG(TEXT(centerXPoint));

		LOG("NUM");
		localindex = fontIndexHelper(text[i]);

		int uvx = localindex % 16;
		int uvy = floor(localindex / 16);
		
		LOG(TEXT(uvy * uvoffset + 1 * uvoffset), TEXT(uvx * uvoffset + 1 * uvoffset));
	



		vertices[i * 4 + 0] = meshData(
			vec3(centerXPoint - halfspan,+halfspan,0),
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


		//indicies 0, 1, 2, 2, 1, 3

		indices[i * 6 + 0] = i * 4 + 0;
		indices[i * 6 + 1] = i * 4 + 1;
		indices[i * 6 + 2] = i * 4 + 2;
		indices[i * 6 + 3] = i * 4 + 2;
		indices[i * 6 + 4] = i * 4 + 1;
		indices[i * 6 + 5] = i * 4 + 3;


	}


}

