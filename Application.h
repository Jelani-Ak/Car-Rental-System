#pragma once

#include "UserInterface.h"

class Application : public wxApp
{
public:
	Application();
	~Application();

public:
	virtual bool OnInit();

private:
	UserInterface* userInterface = nullptr;
};
