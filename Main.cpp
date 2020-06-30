#include "Main.h"

Main::Main() : wxFrame(nullptr, wxID_ANY, "Car Rental Service", wxPoint(0, 0), wxSize(1265, 685))
{
	SetOwnBackgroundColour(wxColour(245, 245,		245));

	/* 01 Image region*/
	imagePanel = new wxPanel(this, wxID_ANY, wxPoint(10, 10), wxSize(400, 400), wxALL);
	imageSizer = new wxGridBagSizer(5, 5);

	imagePanel->SetBackgroundColour(wxColour(255, 225, 150)); //Visual guidance, remove later
	imagePanel->SetSizer(imageSizer);
	/* 01 End region */

	/* 02 Specifications region */
	specificationsPanel = new wxPanel(this, wxID_ANY, wxPoint(420, 10), wxSize(515, 400));

	specificationsPanel->SetBackgroundColour(wxColour(255, 225, 150)); //Visual guidance, remove later
	/* 02 End region */

	/* 03 Refine search option region */
	refineSearchPanel = new wxPanel(this, wxID_ANY, wxPoint(945, 10), wxSize(295, 400));
	refineSearchSizer = new wxGridBagSizer(10, 5);

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

	//Search
	refineSearchSizer->Add(new wxStaticText(refineSearchPanel, 0, _("Search car Model:"), wxDefaultPosition, wxSize(100, 23)), wxGBPosition(0, 0));
	refineSearchSizer->Add(new wxTextCtrl(refineSearchPanel, 1, _("Enter Text"), wxDefaultPosition)), wxSize(100, 23), wxGBPosition(0, 1);

	//Number of Doors
	refineSearchSizer->Add(new wxStaticText(refineSearchPanel, 2, _("Number of Doors:"), wxDefaultPosition, wxSize(100, 23)), wxGBPosition(1, 0));
	refineSearchSizer->Add(new wxSpinCtrl(refineSearchPanel, 3, _("2"), wxDefaultPosition, wxSize(75, 23)), wxGBPosition(1, 1));

	//Engine Size
	refineSearchSizer->Add(new wxStaticText(refineSearchPanel, 4, _("Engine Size:"), wxDefaultPosition, wxSize(100, 23)), wxGBPosition(2, 0));
	refineSearchSizer->Add(new wxComboBox(refineSearchPanel, 5, _("Select Size"), wxDefaultPosition, wxSize(100, 23), *engineSizes), wxGBPosition(2, 1));

	//Number of seats
	refineSearchSizer->Add(new wxStaticText(refineSearchPanel, 6, _("Number of Seats:"), wxDefaultPosition, wxSize(100, 23)), wxGBPosition(3, 0));
	refineSearchSizer->Add(new wxSpinCtrl(refineSearchPanel, 7, _("2"), wxDefaultPosition, wxSize(75, 23)), wxGBPosition(3, 1));

	//Minimum and Maximum mileage slider
	refineSearchSizer->Add(new wxStaticText(refineSearchPanel, 8, _("Mileage:"), wxDefaultPosition, wxSize(100, 23)), wxGBPosition(4, 0));
	refineSearchSizer->Add(new wxStaticText(refineSearchPanel, 8, _("Minimum"), wxDefaultPosition, wxSize(100, 23)), wxGBPosition(5, 0));
	refineSearchSizer->Add(new wxSlider(refineSearchPanel, 9, 10000, 0, 150000, wxDefaultPosition, wxSize(295, 23), wxSL_HORIZONTAL | wxSL_VALUE_LABEL | wxSL_SELRANGE), wxGBPosition(6, 0), wxGBSpan(1, 2), wxBOTTOM, 5);
	refineSearchSizer->Add(new wxStaticText(refineSearchPanel, 8, _("Maximum"), wxDefaultPosition, wxSize(100, 23)), wxGBPosition(7, 0));
	refineSearchSizer->Add(new wxSlider(refineSearchPanel, 10, 10000, 0, 150000, wxDefaultPosition, wxSize(295, 23), wxSL_HORIZONTAL | wxSL_VALUE_LABEL | wxSL_SELRANGE), wxGBPosition(8, 0), wxGBSpan(1, 2));
		
	//Submit Button
	refineSearchSizer->Add(new wxButton(refineSearchPanel, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize), wxGBPosition(10, 0));

	refineSearchPanel->SetBackgroundColour(wxColour(255, 225, 150)); //Visual guidance, remove later
	refineSearchPanel->SetSizer(refineSearchSizer);
	refineSearchPanel->SetAutoLayout(true);
	refineSearchPanel->Layout();
	/* 03 End region */

	//Table
	CarRentalTable* carRentTable = new CarRentalTable(this);
}

Main::~Main()
{

}

CarRentalTable::CarRentalTable(Main* parent) : wxGrid(parent, wxID_ANY)
{
	//Dimensions and Formatting
	CreateGrid(10, 8);
	EnableEditing(false);
	DisableDragColSize();
	DisableDragRowSize();
	SetRowLabelSize(25);
	SetColLabelSize(25);
	SetSize(wxSize(1230, 215));
	SetPosition(wxPoint(10, 420));
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
		SetColSize(i, ((1230-25)/8)); // ((wxSize Width - RowLabelSize)/ n Columns) || (1230-25)/8)
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

//Event Handlers
wxBEGIN_EVENT_TABLE(Main, wxFrame)
	EVT_BUTTON(10001, AddString) //Test, remove later
	EVT_BUTTON(10002, RemoveStrings) //Test, remove later
	EVT_BUTTON(1, AddString) //Test, remove later
wxEND_EVENT_TABLE()

//Add string to the list (Test function, remove later)
void Main::AddString(wxCommandEvent &evt)
{
	if (!textBox->IsEmpty()) {
		listBox->AppendString(textBox->GetValue());
		textBox->Clear();
	}
	evt.Skip();
}

//Clear all strings (Test function, remove later)
void Main::RemoveStrings(wxCommandEvent &evt)
{
	if (!listBox->IsEmpty()) {
		listBox->Clear();
	}
	evt.Skip();
}
