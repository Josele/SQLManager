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
#include <wx/filedlg.h>
#include <windows.h>
//(*InternalHeaders(SQLManagerFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)
using std::string;
HINSTANCE histDLL;
//helper functions
//try to work with an array
typedef int (*Myfunc) (sqlite3**,string);
typedef int (*Myfunc2) (sqlite3*,string);
typedef int (*Myfunc3) (sqlite3*,string,char*  );
typedef int (*Myfunc4) (sqlite3* , string ,string );
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
const long SQLManagerFrame::ID_LISTBOX = wxNewId();
const long SQLManagerFrame::ID_STATICLINE1 = wxNewId();
const long SQLManagerFrame::ID_BigBox = wxNewId();
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
    ListBox = new wxListBox(this, ID_LISTBOX, wxDefaultPosition, wxSize(132,224), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX"));
    FlexGridSizer1->Add(ListBox, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(1,208), wxLI_VERTICAL, _T("ID_STATICLINE1"));
    FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BigBox = new wxTextCtrl(this, ID_BigBox, _("Text"), wxDefaultPosition, wxSize(532,228), 0, wxDefaultValidator, _T("ID_BigBox"));
    FlexGridSizer1->Add(BigBox, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE|wxALIGN_RIGHT|wxALIGN_TOP, 5);
    Delete = new wxButton(this, ID_deleteitem, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_deleteitem"));
    FlexGridSizer1->Add(Delete, 1, wxALL|wxFIXED_MINSIZE|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxFIXED_MINSIZE|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Save = new wxButton(this, ID_Save, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Save"));
    BoxSizer1->Add(Save, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Run = new wxButton(this, ID_Run, _("Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Run"));
    BoxSizer1->Add(Run, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxFIXED_MINSIZE|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
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
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_LISTBOX,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnListBox1Select);
    Connect(ID_BigBox,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SQLManagerFrame::OnTextCtrl1Text);
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
*   Description: Fills the listbox
*   Parms: void
*   Return: void
**/
void SQLManagerFrame::lb_reload()
{

}


/**
*   Description: Pops up a Filedialog windows and call de DLL and create a new database
*   Parms: An Event
*   Return: void
**/
void SQLManagerFrame::OnMenuNewSelected(wxCommandEvent& event)
{ wxFileDialog  SaveFileDialog(this, _("Save db file"), "", "",
                       "*.db", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    Myfunc mifunc(0);
    Myfunc3 mifunc3(0);
    string dbname;
    string tbname="datos";
    char* db_err=0;
    int result;
    int result2;
    histDLL= LoadLibrary(FilePath.c_str());
    if (SaveFileDialog.ShowModal() != wxID_OK)
        return;
    dbname=SaveFileDialog.GetPath();
    mifunc=(Myfunc)GetProcAddress(histDLL,"CreateDatabase");
    result=(mifunc)(&db,dbname);
    mifunc3=(Myfunc3)GetProcAddress(histDLL,"CreateTable");
    result2=(mifunc3)(db,tbname,db_err);
    FreeLibrary(histDLL);
    if(result!=0||result2!=0)
    {
        BigBox->Clear();
        BigBox->SetForegroundColour(wxColour(247,34,34));
        std::ostream stream(BigBox);
        stream << " Sqlite3 code error :" <<db_err << "\n";
        sqlite3_free(db_err);
        stream.flush();
        return;
    }
    BigBox->Clear();
   lb_reload();

}

/**
*   Description: Pops up a Filedialog windows and call de DLL and open a new database
*   Parms: An Event
*   Return: void
**/
void SQLManagerFrame::OnMenuLoadSelected(wxCommandEvent& event)
{   wxFileDialog
        OpenFileDialog(this, _("Open db file"), "", "",
                       "*.db", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    Myfunc mifunc(0);
    int result;
    string dbname;
    histDLL= LoadLibrary(FilePath.c_str());
    result=OpenFileDialog.ShowModal();
    if(result!=wxID_OK)
        return;
    dbname=OpenFileDialog.GetPath();
    mifunc=(Myfunc)GetProcAddress(histDLL,"CreateDatabase");
    result=(mifunc)(&db,dbname);
    FreeLibrary(histDLL);
    if(result!=0)
       {
        BigBox->Clear();
        BigBox->SetForegroundColour(wxColour(247,34,34));
        std::ostream stream(BigBox);
        stream << " Sqlite3 code error :" << result << "\n";
        stream.flush();
        return;
        }

     BigBox->Clear();
}




void SQLManagerFrame::OnListBox1Select(wxCommandEvent& event)
{
}

void SQLManagerFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
}
