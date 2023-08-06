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


	virtual void Shutdown(const char* requestID);

	virtual void Startup();

	DragonPTR(Window)m_gameWindow;
	DragonPTR(Input)m_gameInput;
private:
	bool m_isRunning = true;



	float deltaTime = 0.0f;

	gameSettings m_GameSettings;

	Main() {}

	virtual void InitializeComponents();
	virtual void Loop();

	static Main s_instance;

};


