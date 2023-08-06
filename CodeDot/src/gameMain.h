#pragma once
#include "Modules/IO/File.h"
#include "Rendering/Window.h"
#include "Modules/IO/Input.h"
#include "Main.h"

class gameMain : public Main
{


public:
	void Shutdown(const char* requestID) override;


	void Startup() override;

private:
	void InitializeComponents() override;


	void Loop() override;

};


