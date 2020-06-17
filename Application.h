#pragma once

#include "Main.h"

class Application : public wxApp
{
public:
	Application();
	~Application();

public:
	virtual bool OnInit();

private:
	Main* m_frame = nullptr;
};



