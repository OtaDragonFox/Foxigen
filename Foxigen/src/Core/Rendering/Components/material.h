#pragma once
#include"string"


enum class materialErrorType
{
	vertex,
	fragment,
	program
};


class material
{
public:
	void compileShader(const char* vertexPath, const char* fragmentPath);
	

	void checkRenderError(materialErrorType programType, int programIndex);


	int getMaterial() {
		return shaderProgram;
	}

	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;



private:
	unsigned int shaderProgram;
	


private: //error Logging variables.
	int  success;
	char infoLog[512];

};

