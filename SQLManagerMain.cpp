/***************************************************************
 * Name:      SQLManagerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Jose Luis Moragas ()
 * Created:   2015-06-26
 * Copyright: Jose Luis Moragas ()
 * License:
 **************************************************************/

#include "SQLManagerMain.h"
#include <wx/msgdlg.h>

#include <windows.h>
//(*InternalHeaders(SQLManagerFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)
using std::string;
HINSTANCE histDLL;
//helper functions
typedef int (*Myfunc) (sqlite3**,string);
typedef int (*Myfunc2) (sqlite3*,string&);
typedef int (*Myfunc3) (sqlite3*,string);
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(SQLManagerFrame)
const long SQLManagerFrame::ID_LISTBOX1 = wxNewId();
const long SQLManagerFrame::ID_STATICLINE1 = wxNewId();
const long SQLManagerFrame::ID_TEXTCTRL1 = wxNewId();
const long SQLManagerFrame::ID_deleteitem = wxNewId();
const long SQLManagerFrame::ID_Save = wxNewId();
const long SQLManagerFrame::ID_Run = wxNewId();
const long SQLManagerFrame::ID_MenuNew = wxNewId();
const long SQLManagerFrame::idMenuLoad = wxNewId();
const long SQLManagerFrame::idMenuQuit = wxNewId();
const long SQLManagerFrame::idMenuAbout = wxNewId();
const long SQLManagerFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SQLManagerFrame,wxFrame)
    //(*EventTable(SQLManagerFrame)
    //*)
END_EVENT_TABLE()

SQLManagerFrame::SQLManagerFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(SQLManagerFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(132,224), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    FlexGridSizer1->Add(ListBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(1,208), wxLI_VERTICAL, _T("ID_STATICLINE1"));
    FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxSize(532,228), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_TOP, 5);
    Delete = new wxButton(this, ID_deleteitem, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_deleteitem"));
    FlexGridSizer1->Add(Delete, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    FlexGridSizer1->Add(0,0,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Save = new wxButton(this, ID_Save, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Save"));
    BoxSizer1->Add(Save, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Run = new wxButton(this, ID_Run, _("Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Run"));
    BoxSizer1->Add(Run, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, ID_MenuNew, _("New db\tAlt-N"), _("Create a new data base"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, idMenuLoad, _("Load db\tAlt-L"), _("Load a data Base"), wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnListBox1Select);
    Connect(ID_MenuNew,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnMenuNewSelected);
    Connect(idMenuLoad,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnMenuLoadSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnAbout);
    //*)

     db =0;
   FilePath=TEXT("SQLDLL.dll");
    CreateDirectoryW(FilePath.c_str(), NULL);


}

SQLManagerFrame::~SQLManagerFrame()
{
    //(*Destroy(SQLManagerFrame)
    //*)
}

void SQLManagerFrame::OnQuit(wxCommandEvent& event)
{

    Close();
}

void SQLManagerFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void SQLManagerFrame::OnClose(wxCloseEvent& event)
{
    sqlite3_close(db);
    FreeLibrary(histDLL);
      //  Close();
   wxWindow::Destroy();
}


/**
*   Description: Pops up a new windows and call de DLL and create a new database
*   Parms: An Event
*   Return: void
**/
void SQLManagerFrame::OnMenuNewSelected(wxCommandEvent& event)
{


}

void SQLManagerFrame::OnMenuLoadSelected(wxCommandEvent& event)
{
histDLL= LoadLibrary(FilePath.c_str());

    Myfunc mifunc(0);
    int result;
    string dbname;
    result=FileDialog1->ShowModal();
    if(result==wxID_OK)
    {
       dbname=FileDialog1->GetPath();
       mifunc=(Myfunc)GetProcAddress(histDLL,"CreateDatabase");
       (mifunc)(&db,dbname);
    }
FreeLibrary(histDLL);
}




void SQLManagerFrame::OnListBox1Select(wxCommandEvent& event)
{
}
