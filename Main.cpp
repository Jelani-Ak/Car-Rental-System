#include "Main.h"

Main::Main() : wxFrame(nullptr, wxID_ANY, "Car Rental Service Application", wxPoint(0, 0), wxSize(665, 685))
{
	m_btn = new wxButton(this, 10001, "Add", wxPoint(10, 10), wxSize(150,50)); //(Test, remove later)
	m_btn = new wxButton(this, 10002, "Clear", wxPoint(170, 10), wxSize(150,50)); //(Test, remove later)

	m_txt1 = new wxTextCtrl(this, 10003, "", wxPoint(10, 70), wxSize(310, 30)); //(Test, remove later)
	m_txt2 = new wxTextCtrl(this, 10004, "", wxPoint(330, 70), wxSize(310, 30)); //(Test, remove later)

	m_list1 = new wxListBox(this, 10005, wxPoint(10, 110), wxSize(310, 300)); //(Test, remove later)
	m_list2 = new wxListBox(this, 10006, wxPoint(330, 110), wxSize(310, 300)); //(Test, remove later)

	CarRentalTable* carRentTable = new CarRentalTable(this);
}

Main::~Main()
{

}

CarRentalTable::CarRentalTable(Main* parent) : wxGrid(parent, wxID_ANY)
{
	//Dimensions and Formatting
	CreateGrid(10, 5);
	EnableEditing(false);
	DisableDragColSize();
	DisableDragRowSize();
	SetRowLabelSize(0);
	SetColLabelSize(25);
	SetSize(wxSize(630, 215));
	SetPosition(wxPoint(10, 420));
	SetRowLabelAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
	SetLabelFont(wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

	//Column Headings
	SetColLabelValue(0, "Manufacturer");
	SetColLabelValue(1, "Model");
	SetColLabelValue(2, "Rented Date");
	SetColLabelValue(3, "Return Date"); 
	SetColLabelValue(4, "Price");
	//Add more columns later

	//Cell Values (Test, remove later)
	SetCellValue(0, 0, "Suabru");
	SetCellValue(0, 1, "WRX STi - 2004");
	SetCellValue(0, 2, "04/05/2020");
	SetCellValue(0, 3, "04/06/2020");
	SetCellValue(0, 4, "£150");
	
	SetCellValue(1, 0, "Volkswagen");
	SetCellValue(1, 1, "Golf MK4");
	SetCellValue(1, 2, "01/02/2020");
	SetCellValue(1, 3, "01/03/2020");
	SetCellValue(1, 4, "£75");
	//Cell Values (End Here)

	//Set columns to a fixed size
	for (int i = 0; i < 5; i++)
	{
		SetColSize(i, 126); // ((Width - RowLabelSize)/ n Columns)
	}

	//Alternating row colours
	const int colour = 250;
	for (int i = 0; i < 10; i += 2)
	{
		for (int j = 0; j < 5; j++)
		{
			SetCellBackgroundColour(i, j, wxColour(colour, colour, colour));
		}
	}
}

//Event Handlers
wxBEGIN_EVENT_TABLE(Main, wxFrame)
	EVT_BUTTON(10001, AddString)
	EVT_BUTTON(10002, RemoveStrings)
wxEND_EVENT_TABLE()

//Add string to the list (Test, remove function later)
void Main::AddString(wxCommandEvent &evt)
{
	if (!m_txt1->IsEmpty()) {
		m_list1->AppendString(m_txt1->GetValue());
	}
	evt.Skip();
}

//Clear all strings (Test, remove function later)
void Main::RemoveStrings(wxCommandEvent &evt)
{
	if (!m_list1->IsEmpty()) {
		m_list1->Clear();
	}
	evt.Skip();
}