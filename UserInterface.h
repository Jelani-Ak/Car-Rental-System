#pragma once

#include <wx/wx.h>
#include <wx/grid.h>
#include <wx/gbsizer.h>
#include <wx/spinctrl.h>
#include <wx/generic/statbmpg.h>

class UserInterface : public wxFrame
{

public:
	UserInterface();
	~UserInterface();

protected:
	wxGridBagSizer* imageSizer = nullptr;
	wxGridBagSizer* specificationsSizer = nullptr;
	wxComboBox* engineSizeComboBox = nullptr;
	wxPanel* imagePanel = nullptr;
	wxStaticBox* specificationsPanel = nullptr;
	wxPanel* testPanel = nullptr;	
	wxBitmap* manufacturerLogo = nullptr;
	wxGrid* carRentTable = nullptr;

	//wxDECLARE_EVENT_TABLE();
};

class CarRentalTable : public wxGrid
{
public:
	CarRentalTable(UserInterface* parent);
};


class RefineSearchPanel : public wxStaticBox
{
public:
	RefineSearchPanel(UserInterface* parent);

protected:
	wxArrayString* carClass = nullptr;
	wxArrayString* fuelType = nullptr;
	wxArrayString* engineSizes = nullptr;
	wxArrayString* gearboxType = nullptr;

	wxStaticBox* refineSearchPanel = nullptr;
	wxGridBagSizer* refineSearchSizer = nullptr;
};
