#include "TesterDialog.h"

//(*InternalHeaders(TesterDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/valnum.h>
#include <sstream>


//(*IdInit(TesterDialog)
const long TesterDialog::ID_STATICTEXT1 = wxNewId();
const long TesterDialog::ID_TEXTCTRL1 = wxNewId();
const long TesterDialog::ID_STATICLINE1 = wxNewId();
const long TesterDialog::ID_GRID1 = wxNewId();
const long TesterDialog::ID_SPLITTERWINDOW1 = wxNewId();
const long TesterDialog::ID_STATICLINE2 = wxNewId();
const long TesterDialog::ID_Launch = wxNewId();
//*)


BEGIN_EVENT_TABLE(TesterDialog,wxDialog)
	//(*EventTable(TesterDialog)
	//*)
END_EVENT_TABLE()

TesterDialog::TesterDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    wxIntegerValidator<unsigned long>val(&m_value, wxNUM_VAL_THOUSANDS_SEPARATOR);
	//(*Initialize(TesterDialog)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Tester"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxTAB_TRAVERSAL|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(570,309));
	SetMinSize(wxSize(-1,-1));
	SetMaxSize(wxSize(-1,-1));
	FlexGridSizer1 = new wxFlexGridSizer(5, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(2);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Times"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("10"), wxDefaultPosition, wxDefaultSize, 0, val, _T("ID_TEXTCTRL1"));
	BoxSizer1->Add(TextCtrl1, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer1, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	FlexGridSizer1->Add(StaticLine1, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
	SplitterWindow1 = new wxSplitterWindow(this, ID_SPLITTERWINDOW1, wxDefaultPosition, wxDefaultSize, wxSP_3D, _T("ID_SPLITTERWINDOW1"));
	SplitterWindow1->SetMinSize(wxSize(10,10));
	SplitterWindow1->SetMinimumPaneSize(10);
	SplitterWindow1->SetSashGravity(0.5);
	Grid1 = new wxGrid(SplitterWindow1, ID_GRID1, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_GRID1"));
	SplitterWindow1->Initialize(Grid1);
	FlexGridSizer1->Add(SplitterWindow1, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	FlexGridSizer1->Add(StaticLine2, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Launch = new wxButton(this, ID_Launch, _("Launch"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Launch"));
	BoxSizer2->Add(Launch, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, wxID_CANCEL, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	SetSizer(FlexGridSizer1);
	Layout();

	Connect(ID_Launch,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TesterDialog::OnLaunchClick);
	//*)
}

TesterDialog::~TesterDialog()
{
	//(*Destroy(TesterDialog)
	//*)
}
template<class T>
string TesterDialog::toString(T data)
{
    std::stringstream ss;
    ss << data;
    return ss.str();
}

void TesterDialog::GenerateGrid(int col,int row)
{
    int n;
    Grid1->CreateGrid(row,col+1);
    for(n=0;n<col;n++)
        Grid1->SetColLabelValue(n,"P"+toString(n));
    Grid1->SetColLabelValue(n,"Return");
	Grid1->EnableEditing(true);
	Grid1->EnableGridLines(true);
	Grid1->SetDefaultCellFont( Grid1->GetFont() );
	Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
	//Grid1->EnableEditing(false);
}

void TesterDialog::RowName(string name,int row)
{
       Grid1->SetRowLabelValue(row,name);
}
void TesterDialog::ColorSet(std::list<string> mylist,int row)
{
    string temp;
    int n=0;

    while( !mylist.empty() )
    {
        //Grid1->SetReadOnly(row,n,false);
        temp=mylist.front();

            if("int"==temp)
                Grid1->SetCellBackgroundColour(row,n,wxColour(255,0,0));
            else if("double"==temp)
                Grid1->SetCellBackgroundColour(row,n,wxColour(0,0,255));

            else if("char*"==temp)
                Grid1->SetCellBackgroundColour(row,n,wxColour(0,255,0));



        n++;
        mylist.pop_front();
    }

    }


void TesterDialog::OnLaunchClick(wxCommandEvent& event)
{

    Grid1->SetCellValue( 0, 1, "wxGrid is good" );
    Grid1->SetCellValue( 0, 5, Grid1->GetCellValue (0,0) );

}
