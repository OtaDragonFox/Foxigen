#pragma once
#include "Modules/IO/File.h"
#include "Rendering/Window.h"
#include "Modules/IO/Input.h"

class Main
{
public:

	static Main& Get()
	{
		return s_instance;
	}


	void Shutdown(const char* requestID);

	void Startup();

	DragonPTR(Window)m_gameWindow;
	DragonPTR(Input)m_gameInput;
	static Main s_instance;

private:
	bool m_isRunning = true;



	float deltaTime = 0.0f;

	gameSettings m_GameSettings;

	Main() {}

	void InitializeComponents();
	void Loop();


};


