///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

frmMain::frmMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	bSizer2 = new wxBoxSizer( wxVERTICAL );

	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer3->Add( m_panel2, 70, wxEXPAND | wxALL, 5 );

	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_button3 = new wxButton( this, wxID_ANY, wxT("clean"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button3, 0, wxALL, 5 );

	m_button4 = new wxButton( this, wxID_ANY, wxT("start dfs"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button4, 0, wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Start node"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer4->Add( m_staticText2, 0, wxALL, 5 );

	m_textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_textCtrl2, 0, wxALL, 5 );

	m_button31 = new wxButton( this, wxID_ANY, wxT("euler "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button31, 0, wxALL, 5 );

	m_button41 = new wxButton( this, wxID_ANY, wxT("Djicstra"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button41, 0, wxALL, 5 );

	m_radioBtn1 = new wxRadioButton( this, wxID_ANY, wxT("weighted graf"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_radioBtn1, 0, wxALL, 5 );

	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("End node"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer4->Add( m_staticText21, 0, wxALL, 5 );

	m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_textCtrl3, 0, wxALL, 5 );


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );


	bSizer2->Add( bSizer3, 70, wxEXPAND, 5 );

	adj = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	adj->CreateGrid( 0, 0 );
	adj->EnableEditing( false );
	adj->EnableGridLines( false );
	adj->SetGridLineColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	adj->EnableDragGridSize( false );
	adj->SetMargins( 0, 0 );

	// Columns
	adj->SetColSize( 0, 30 );
	adj->EnableDragColMove( false );
	adj->EnableDragColSize( true );
	adj->SetColLabelSize( 30 );
	adj->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	adj->SetRowSize( 0, 30 );
	adj->EnableDragRowSize( false );
	adj->SetRowLabelSize( 30 );
	adj->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	adj->SetDefaultCellAlignment( wxALIGN_RIGHT, wxALIGN_TOP );
	bSizer2->Add( adj, 30, wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_panel2->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( frmMain::create_node ), NULL, this );
	m_panel2->Connect( wxEVT_PAINT, wxPaintEventHandler( frmMain::paint ), NULL, this );
	m_panel2->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( frmMain::create_nodes ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmMain::clean ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmMain::start_dfs ), NULL, this );
	m_button31->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmMain::euler_click ), NULL, this );
	m_button41->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmMain::short_path ), NULL, this );
}

frmMain::~frmMain()
{
	// Disconnect Events
	m_panel2->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( frmMain::create_node ), NULL, this );
	m_panel2->Disconnect( wxEVT_PAINT, wxPaintEventHandler( frmMain::paint ), NULL, this );
	m_panel2->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( frmMain::create_nodes ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmMain::clean ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmMain::start_dfs ), NULL, this );
	m_button31->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmMain::euler_click ), NULL, this );
	m_button41->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmMain::short_path ), NULL, this );

}
