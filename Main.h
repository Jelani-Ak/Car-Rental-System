#pragma once

#include "wx/wx.h"
#include "wx/grid.h"

class Main : public wxFrame
{
public:
	Main();
	~Main();	

public:
	void AddString(wxCommandEvent& evt);
	void RemoveStrings(wxCommandEvent& evt);

private:
	wxButton* m_btn = nullptr;

	wxTextCtrl* m_txt1 = nullptr;
	wxTextCtrl* m_txt2 = nullptr;

	wxListBox* m_list1 = nullptr;
	wxListBox* m_list2 = nullptr;

	wxDECLARE_EVENT_TABLE();
};

class CarRentalTable : public wxGrid
{
public:
	CarRentalTable(Main* parent);
};