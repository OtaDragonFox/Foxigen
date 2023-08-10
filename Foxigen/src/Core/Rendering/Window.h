#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "core/Rendering/Components/mesh.h"

#include "dragonmath.h"
#include <game/Rendering/text.h>



class Window
{
public:

    bool createWindow();


    

    void updateWindow(float& deltaTime);

    void calculateDeltaTime(float& deltaTime);
    void updateWindowResulution(int width, int height);
    void shutDownWindow();

    
    void setBackgroundColor(vec3 newColor) {
        bgColor = newColor;
    }

    GLFWwindow* m_app_window;

    vec2 windowsize;

private:
	vec3 bgColor = vec3(1,0,0);


    text testMesh;

    float lastTime = 0.0f;



};

