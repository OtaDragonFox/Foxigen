#include <dragoncore.h>
#include "Window.h"


#include <Main.h>
#include <Modules/IO/Logger.h>



/*
    
    GLFW callback forwards

*/

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{

    CORE.Get().m_gameWindow.get()->updateWindowResulution(width,height);
}


/*

        Class functions

*/

bool Window::createWindow()
{


    //load window settings



    if (!glfwInit())
    {
        return false;
    }
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_app_window = glfwCreateWindow(640, 480, "Hello world", NULL /*Monitor Context*/, NULL /*GLFW window Context*/);
    if (!m_app_window)
    {
        return false;
    }

    glfwMakeContextCurrent(m_app_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        LOG("Failed to load GLAD");
        return 0;
    }


    glViewport(0, 0, 640, 480);

    glfwSetFramebufferSizeCallback(m_app_window, framebuffer_size_callback);

    lastTime = float(glfwGetTime());

    testMesh.updateMesh();
    
    return true;
}

void Window::shutDownWindow()
{
    glfwTerminate();
}

void Window::updateWindow(float& deltaTime)
{
    glClearColor(bgColor.x, bgColor.y, bgColor.z,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    testMesh.renderMesh();


    glfwSwapBuffers(m_app_window);
    glfwPollEvents();

}

void Window::calculateDeltaTime(float & deltaTime)
{
    deltaTime = float(glfwGetTime()) - lastTime;
    lastTime = float(glfwGetTime());
}

void Window::updateWindowResulution(int width, int height)
{
}
