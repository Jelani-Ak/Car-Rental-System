#pragma once

#include <wx/wx.h>
#include <wx/grid.h>
#include <wx/gbsizer.h>
#include <wx/spinctrl.h>

class Main : public wxFrame
{
public:
	Main();
	~Main();	

public:
	void AddString(wxCommandEvent& evt);
	void RemoveStrings(wxCommandEvent& evt);

protected:

	wxGridBagSizer* refineSearchSizer = nullptr;
	wxGridBagSizer* imageSizer = nullptr;
	wxComboBox* engineSizeComboBox = nullptr;
	wxPanel* imagePanel = nullptr;
	wxPanel* specificationsPanel = nullptr;
	wxPanel* refineSearchPanel = nullptr;
	wxArrayString* engineSizes = nullptr;

	wxButton* button = nullptr; //Remove Later
	wxStaticBox* titledBorder = nullptr;  //Remove Later
	wxSpinCtrl* spinner = nullptr;  //Remove Later
	wxStaticText* textLabel = nullptr;  //Remove Later
	wxTextCtrl* textBox = nullptr;  //Remove Later
	wxListBox* listBox = nullptr;  //Remove Later

	wxDECLARE_EVENT_TABLE();
};

class CarRentalTable : public wxGrid
{
public:
	CarRentalTable(Main* parent);
};
