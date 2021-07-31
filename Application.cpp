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
	userInterface = new UserInterface();
	userInterface->Show();

	return true;
}
