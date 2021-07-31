#include "UserInterface.h"

UserInterface::UserInterface() : wxFrame(nullptr, wxID_ANY, "Car Rental System", wxDefaultPosition, wxSize(1265, 685))
{
	SetOwnBackgroundColour(wxColour(245, 245, 245));

	/* 01 Image region */
	imagePanel = new wxPanel(this, wxID_ANY, wxPoint(10, 10), wxSize(400, 400), wxALL);
	imageSizer = new wxGridBagSizer();

	imageSizer->Add(new wxGenericStaticBitmap(imagePanel, wxID_ANY, wxBitmap((wxGetCwd() + "\\images\\subaru.bmp"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize),
		wxGBPosition(0, 0), wxGBSpan(1, 1), wxALL, 70);

	imagePanel->SetBackgroundColour(wxColour(255, 225, 150)); //Visual guidance, remove later
	imagePanel->SetSizer(imageSizer);
	imagePanel->SetAutoLayout(true);
	imagePanel->Layout();
	/* 01 End region */

	/* 02 Specifications region */
	specificationsPanel = new wxStaticBox(this, wxID_ANY, _("Car Specifications"), wxPoint(420, 10), wxSize(515, 400));
	specificationsSizer = new wxGridBagSizer();

	specificationsSizer->Add(new wxStaticText(specificationsPanel, wxID_ANY, _(""), wxDefaultPosition, wxSize(0, 0)), wxGBPosition(0, 0), wxGBSpan(1, 2), wxTOP | wxBOTTOM, 5); //Dummy widget for padding);
	specificationsSizer->Add(new wxStaticText(specificationsPanel, wxID_ANY, _("ADD SCROLLABLE PANEL HERE")), wxGBPosition(1, 0), wxGBSpan(1, 2), wxTOP | wxLEFT | wxRIGHT, 10);
	specificationsSizer->Add(new wxStaticText(specificationsPanel, wxID_ANY, _("ADD COLLAPSIBLE SPECIFICATIONS HERE")), wxGBPosition(2, 0), wxGBSpan(1, 2), wxTOP | wxLEFT | wxRIGHT, 10);
	
	specificationsPanel->SetSizer(specificationsSizer);
	specificationsPanel->SetAutoLayout(true);
	specificationsPanel->Layout();
	//specificationsPanel->SetBackgroundColour(wxColour(255, 225, 150)); //Visual guidance, remove later
	/* 02 End region */

	CarRentalTable* carRentTable = new CarRentalTable(this);
	RefineSearchPanel* refineSearchPanel = new RefineSearchPanel(this);
}

UserInterface::~UserInterface() 
{

}

CarRentalTable::CarRentalTable(UserInterface* parent) : wxGrid(parent, wxID_ANY, wxPoint(10, 420), wxSize(1230, 215))
{
	//Demensions and Formatting
	CreateGrid(10, 8);
	EnableEditing(false);
	DisableDragColSize();
	DisableDragRowSize();
	SetRowLabelSize(25);
	SetColLabelSize(25);
	SetRowLabelAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
	SetLabelFont(wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

	//Column Headings
	SetColLabelValue(0, "Manufacturer");
	SetColLabelValue(1, "Class");
	SetColLabelValue(2, "Model");
	SetColLabelValue(3, "Mileage");
	SetColLabelValue(4, "Rented Date");
	SetColLabelValue(5, "Return Date");
	SetColLabelValue(6, "Price");
	SetColLabelValue(7, "<Placeholder>");

	//Cell Values (Test, remove later)
	SetCellValue(0, 0, "Suabru");
	SetCellValue(0, 1, "Sedan/Saloon");
	SetCellValue(0, 2, "WRX STi - 2004");
	SetCellValue(0, 3, "75,324");
	SetCellValue(0, 4, "04/05/2020");
	SetCellValue(0, 5, "04/06/2020");
	SetCellValue(0, 6, "£150");
	SetCellValue(0, 7, "<Placeholder>");

	SetCellValue(1, 0, "Volkswagen");
	SetCellValue(1, 1, "Hatchback");
	SetCellValue(1, 2, "Golf MK4");
	SetCellValue(1, 3, "96,594");
	SetCellValue(1, 4, "01/02/2020");
	SetCellValue(1, 5, "01/03/2020");
	SetCellValue(1, 6, "£75");
	SetCellValue(1, 7, "<Placeholder>");
	//Cell Values (End Here)

	//Set columns to a fixed size
	for (int i = 0; i <= 7; i++)
	{
		SetColSize(i, ((1230 - 25) / 8)); // ((wxSize Width - RowLabelSize)/ n Columns) || (1230-25)/8)
	}
	SetColSize(7, 155);


	//Alternating row colours
	for (int i = 0; i < 10; i += 2)
	{
		for (int j = 0; j < 8; j++)
		{
			SetCellBackgroundColour(i, j, wxColour(240, 240, 240));
		}
	}
}

RefineSearchPanel::RefineSearchPanel(UserInterface* parent) : wxStaticBox(parent, wxID_ANY, _("Filter"), wxPoint(945, 10), wxSize(295, 400))
{
	refineSearchSizer = new wxGridBagSizer();

	//Engine Size Array
	engineSizes = new wxArrayString();
	engineSizes->Add("1.0L");
	engineSizes->Add("1.2L");
	engineSizes->Add("1.4L");
	engineSizes->Add("1.6L");
	engineSizes->Add("1.8L");
	engineSizes->Add("2.0L");
	engineSizes->Add("2.2L");
	engineSizes->Add("2.4L");
	engineSizes->Add("2.6L");
	engineSizes->Add("2.8L");
	engineSizes->Add("3.0L");

	//Car Type Array
	carClass = new wxArrayString();
	carClass->Add("Micro");
	carClass->Add("Sedan");
	carClass->Add("CUV");
	carClass->Add("SUV");
	carClass->Add("Hatchback");
	carClass->Add("Roadster");
	carClass->Add("Pickup");
	carClass->Add("Van");
	carClass->Add("Coupe");
	carClass->Add("Cabriole");
	carClass->Add("Minivan");

	//Fuel Type Array
	fuelType = new wxArrayString();
	fuelType->Add("Petrol");
	fuelType->Add("Diesel");
	fuelType->Add("Hybrid");
	fuelType->Add("Electric");

	//Gearbox Type Array
	gearboxType = new wxArrayString();
	gearboxType->Add("Manual");
	gearboxType->Add("Automatic");
	gearboxType->Add("Electric");

	int gridPosition = 0;
	refineSearchSizer->Add(new wxStaticText(this, wxID_ANY, _(""), wxDefaultPosition, wxSize(0, 0)),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 2), wxTOP, 2); //Dummy widget for padding

	//Text Search
	refineSearchSizer->Add(new wxStaticText(this, wxID_ANY, _("Search by Name:"), wxDefaultPosition, wxSize(100, 23)),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10); //Text Label
	refineSearchSizer->Add(new wxTextCtrl(this, 1, _("Enter Text"), wxDefaultPosition, wxSize(140, 23)),
		wxGBPosition(gridPosition, 1), wxGBSpan(1, 1), wxBOTTOM | wxLEFT | wxRIGHT, 10); //Textbox

	//Number of Doors
	refineSearchSizer->Add(new wxStaticText(this, wxID_ANY, _("Number of Doors:"), wxDefaultPosition, wxSize(100, 23)),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10); //Text Label
	refineSearchSizer->Add(new wxSpinCtrl(this, 2, _("2"), wxDefaultPosition, wxSize(140, 23)),
		wxGBPosition(gridPosition, 1), wxGBSpan(1, 1), wxBOTTOM | wxLEFT | wxRIGHT, 10); //Spinner

	//Engine Size
	refineSearchSizer->Add(new wxStaticText(this, wxID_ANY, _("Engine Size:"), wxDefaultPosition, wxSize(100, 23)),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10); //Text Label
	refineSearchSizer->Add(new wxComboBox(this, 3, _("Select Engine Size"), wxDefaultPosition, wxSize(140, 23), *engineSizes),
		wxGBPosition(gridPosition, 1), wxGBSpan(1, 1), wxBOTTOM | wxLEFT | wxRIGHT, 10); //ComboBox

	//Gearbox (No space for this currently)
	/*
	refineSearchSizer->Add(new wxStaticText(this, wxID_ANY, _("Gearbox:"), wxDefaultPosition, wxSize(100, 23)),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10); //Text Label
	refineSearchSizer->Add(new wxComboBox(this, 4, _("Select Gearbox"), wxDefaultPosition, wxSize(140, 23), *gearboxType),
		wxGBPosition(gridPosition, 1), wxGBSpan(1, 1), wxBOTTOM | wxLEFT | wxRIGHT, 10); //ComboBox
	*/

	//Fuel Type
	refineSearchSizer->Add(new wxStaticText(this, wxID_ANY, _("Fuel Type:"), wxDefaultPosition, wxSize(100, 23)),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10); //Text Label
	refineSearchSizer->Add(new wxComboBox(this, 5, _("Select Fuel Type"), wxDefaultPosition, wxSize(140, 23), *fuelType),
		wxGBPosition(gridPosition, 1), wxGBSpan(1, 1), wxBOTTOM | wxLEFT | wxRIGHT, 10); //ComboBox

	//Car Class
	refineSearchSizer->Add(new wxStaticText(this, wxID_ANY, _("Car Class:"), wxDefaultPosition, wxSize(100, 23)),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10); //Text Label
	refineSearchSizer->Add(new wxComboBox(this, 6, _("Select Class Type"), wxDefaultPosition, wxSize(140, 23), *carClass),
		wxGBPosition(gridPosition, 1), wxGBSpan(1, 1), wxBOTTOM | wxLEFT | wxRIGHT, 10); //ComboBox

	//Number of Seats
	refineSearchSizer->Add(new wxStaticText(this, wxID_ANY, _("Seat Capacity:"), wxDefaultPosition, wxSize(100, 23)),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10); //Text Label
	refineSearchSizer->Add(new wxSpinCtrl(this, 7, _("2"), wxDefaultPosition, wxSize(140, 23)),
		wxGBPosition(gridPosition, 1), wxGBSpan(1, 1), wxBOTTOM | wxLEFT | wxRIGHT, 10); //Spinner

	//Number of Previous Owners
	refineSearchSizer->Add(new wxStaticText(this, wxID_ANY, _("Previous Owners:"), wxDefaultPosition, wxSize(100, 23)),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10); //Text Label
	refineSearchSizer->Add(new wxSpinCtrl(this, 8, _("2"), wxDefaultPosition, wxSize(140, 23)),
		wxGBPosition(gridPosition, 1), wxGBSpan(1, 1), wxBOTTOM | wxLEFT | wxRIGHT, 10); //Spinner

	//Minimum and Maximum mileage slider
	refineSearchSizer->Add(new wxStaticText(this, wxID_ANY, _("Mileage:"), wxDefaultPosition, wxSize(100, 23)),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10); //Text Label

	refineSearchSizer->Add(new wxStaticText(this, wxID_ANY, _("Minimum"), wxDefaultPosition, wxSize(100, 23)),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 16); //Text Label

	refineSearchSizer->Add(new wxSlider(this, 9, 0, 0, 150000, wxDefaultPosition, wxSize(275, 23),
		wxSL_HORIZONTAL | wxSL_VALUE_LABEL | wxSL_SELRANGE),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 2), wxBOTTOM | wxLEFT | wxRIGHT, 10); //Slider (Minimum)

	refineSearchSizer->Add(new wxStaticText(this, wxID_ANY, _("Maximum"), wxDefaultPosition, wxSize(100, 23)),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 16); //Text Label

	refineSearchSizer->Add(new wxSlider(this, 10, 150000, 0, 150000, wxDefaultPosition, wxSize(275, 23),
		wxSL_HORIZONTAL | wxSL_VALUE_LABEL | wxSL_SELRANGE),
		wxGBPosition(++gridPosition, 0), wxGBSpan(1, 2), wxLEFT | wxRIGHT, 15); //Slider (Maximum)

	SetSizer(refineSearchSizer);
	SetAutoLayout(true);
	Layout();
}
