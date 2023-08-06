#include <dragoncore.h>
#include "gameMain.h"
#include "Modules/IO/Logger.h"

Main Main::s_instance;


int main(int argc, char* argv[])
{
	CORE.Startup();

}


void Main::Startup()
{
	//TODO : Load settings from disk // create empty settings container.

	InitializeComponents();

	while (m_isRunning)
	{

		Loop();


	}
	Shutdown("Game Stopped Running");
}

void Main::InitializeComponents()
{
	m_gameWindow = DragonCLASS(Window);
	if (!m_gameWindow.get()->createWindow())
	{
		Shutdown("Failed To create windows class");
	}
	m_gameInput = DragonCLASS(Input);
	m_gameInput.get()->SetupInputSystem();
}

void Main::Loop()
{
	m_gameWindow.get()->calculateDeltaTime(deltaTime);
	m_gameWindow.get()->updateWindow(deltaTime);
}



void Main::Shutdown(const char* shutdownID)
{
	m_gameWindow->shutDownWindow();
	m_isRunning = false;

	//write the shutdown reason to file to easieaierly do debugging
}

void gameMain::Shutdown(const char* requestID)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void gameMain::Startup()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void gameMain::InitializeComponents()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void gameMain::Loop()
{
	throw std::logic_error("The method or operation is not implemented.");
}
