#include "dragoncore.h"
#include "Input.h"
#include "Logger.h"
#include "Main.h"
#include <GLFW/glfw3.h>


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
		CORE.m_gameInput.get()->setKey(key, true);
	if (action == GLFW_RELEASE)
		CORE.m_gameInput.get()->setKey(key, false);
}



void Input::SetupInputSystem()
{
	glfwSetKeyCallback(CORE.m_gameWindow.get()->m_app_window, key_callback);

}



void Input::setKey(int keycode, bool pressed)
{
	LOG("Key : ", TEXT(keycode), "was ", (pressed) ? "PRESSED" : "RELEASED");
	keymap[keycode] = pressed;
}

bool Input::isKeyPressed(uint16_t keyCode)
{
	if (keyCode > 512)
	{
		LOG("INDEX OUT OF RANGE: ", TEXT(keyCode));
		return false;
	}

	return keymap[keyCode];

}

void Input::printKeyMap()
{
	//Hacky bs but it works ?

	std::string printLine = "00000000";
	for (int x = 0; x < 64; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			printLine[y] = isKeyPressed(x * 8 + y) ? '#' : 'O';
		}
		LOG(printLine);
	}

}
