#include "Application.h"

wxIMPLEMENT_APP(Application);

Application::Application() 
{

}

Application::~Application()
{

}

bool Application::OnInit()
{
	m_frame = new Main();
	m_frame->Show();

	return true;
}