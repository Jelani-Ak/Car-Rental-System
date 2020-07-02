#pragma once

#include <wx/wx.h>
#include <wx/grid.h>
#include <wx/gbsizer.h>
#include <wx/spinctrl.h>
#include <wx/generic/statbmpg.h>

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
	wxPanel* testPanel = nullptr;
	wxStaticBox* refineSearchPanel = nullptr;
	wxArrayString* engineSizes = nullptr;
	wxArrayString* carClass = nullptr;
	wxArrayString* fuelType = nullptr;
	wxBitmap* manufacturerLogo = nullptr;

	//wxDECLARE_EVENT_TABLE();
};

class CarRentalTable : public wxGrid
{
public:
	CarRentalTable(Main* parent);
};
