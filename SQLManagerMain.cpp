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
#include <wx/textdlg.h>
#include <windows.h>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <vector>
#include "CParams.h"
#include "ConfigDialog.h"
 #include "TesterDialog.h"
 #define ID_MODIFYILIST		2001
 #define ID_DELETEILIST 	2002

//(*InternalHeaders(SQLManagerFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)
HINSTANCE histDLL;
//helper functions
//try to work with an array
typedef int (*Createbase) (sqlite3**,const char*);
typedef int (*Callblback)(void*,int,char**,char**);
typedef int (*CreateTable) (sqlite3*,const char*);
typedef int (*add_item) (sqlite3*, const char* ,const char* ,const char* );
typedef int  (*add_params) (sqlite3* , const char* ,const char* ,const char* ,const char* ,const char* ,const char* ,const char* );
typedef int (*add_text) (sqlite3*, const char *,const char *,const char *,const char *,const char *);
typedef int (*del_item) (sqlite3*, const char*  ,const char* );
typedef int (*Getrow) (sqlite3* , const char* ,const char*,const char*,int (*callback)(void*,int,char**,char**),void* );
typedef int (*max_params) (sqlite3* , const char* ,const char*,int (*callback)(void*,int,char**,char**),void* );
typedef int (*Getitem) (sqlite3* , const char* ,const char*,const char*,const char*,const char*,int (*callback)(void*,int,char**,char**),void* );
typedef int (*Nrow) (sqlite3* , const char*,int (*callback)(void*,int,char**,char**),void*  );

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
const long SQLManagerFrame::ID_STATICTEXT1 = wxNewId();
const long SQLManagerFrame::ID_STATICTEXT3 = wxNewId();
const long SQLManagerFrame::ID_LISTBOX = wxNewId();
const long SQLManagerFrame::ID_STATICLINE1 = wxNewId();
const long SQLManagerFrame::ID_LISTCTRL = wxNewId();
const long SQLManagerFrame::ID_STATICTEXT4 = wxNewId();
const long SQLManagerFrame::ID_STATICTEXT5 = wxNewId();
const long SQLManagerFrame::ID_TEXTCTRL2 = wxNewId();
const long SQLManagerFrame::ID_RADIOBOX = wxNewId();
const long SQLManagerFrame::ID_STATICTEXT2 = wxNewId();
const long SQLManagerFrame::ID_BigBox = wxNewId();
const long SQLManagerFrame::ID_deleteitem = wxNewId();
const long SQLManagerFrame::ID_BUTTON1 = wxNewId();
const long SQLManagerFrame::ID_Save = wxNewId();
const long SQLManagerFrame::ID_Run = wxNewId();
const long SQLManagerFrame::ID_Run_All = wxNewId();
const long SQLManagerFrame::ID_PANEL1 = wxNewId();
const long SQLManagerFrame::ID_MenuNew = wxNewId();
const long SQLManagerFrame::idMenuLoad = wxNewId();
const long SQLManagerFrame::idMenuQuit = wxNewId();
const long SQLManagerFrame::ID_Config = wxNewId();
const long SQLManagerFrame::ID_Lib = wxNewId();
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
    wxBoxSizer* BoxSizer4;
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("Dll_Manager"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(600,550));
    SetMinSize(wxSize(-1,-1));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("C:\\Users\\josele\\Pictures\\icon_128.png"))));
    	SetIcon(FrameIcon);
    }
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(288,216), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetMinSize(wxSize(400,-1));
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer1->AddGrowableCol(2);
    FlexGridSizer1->AddGrowableRow(1);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText1->SetMinSize(wxSize(-1,-1));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Panel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ListBox = new wxListBox(Panel1, ID_LISTBOX, wxDefaultPosition, wxSize(132,224), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX"));
    ListBox->SetMinSize(wxSize(-1,-1));
    FlexGridSizer1->Add(ListBox, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxDefaultPosition, wxSize(1,414), wxLI_VERTICAL, _T("ID_STATICLINE1"));
    StaticLine1->SetMinSize(wxSize(-1,-1));
    FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    listCtrl = new wxListCtrl(Panel1, ID_LISTCTRL, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_LISTCTRL"));
    BoxSizer3->Add(listCtrl, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableCol(1);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Return param"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer2->Add(StaticText4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Return type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer2->Add(StaticText5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Parameters = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_RICH2, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer2->Add(Parameters, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxString __wxRadioBoxChoices_1[4] =
    {
    	_("void"),
    	_("int"),
    	_("double"),
    	_("char*")
    };
    RadioBox = new wxRadioBox(Panel1, ID_RADIOBOX, wxEmptyString, wxPoint(-1,-1), wxSize(169,40), 4, __wxRadioBoxChoices_1, 1, wxRA_VERTICAL, wxDefaultValidator, _T("ID_RADIOBOX"));
    RadioBox->SetMinSize(wxSize(-1,-1));
    RadioBox->SetMaxSize(wxSize(-1,-1));
    FlexGridSizer2->Add(RadioBox, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    BoxSizer3->Add(FlexGridSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Code"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText2->SetMinSize(wxSize(-1,-1));
    BoxSizer4->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BigBox = new wxTextCtrl(Panel1, ID_BigBox, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(532,228)), wxTE_AUTO_SCROLL|wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_MULTILINE|wxTE_RICH2|wxVSCROLL, wxDefaultValidator, _T("ID_BigBox"));
    BigBox->SetMinSize(wxSize(400,-1));
    BoxSizer4->Add(BigBox, 2, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_TOP, 6);
    BoxSizer3->Add(BoxSizer4, 2, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Delete = new wxButton(Panel1, ID_deleteitem, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_deleteitem"));
    Delete->SetMinSize(wxSize(-1,-1));
    BoxSizer2->Add(Delete, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Load File"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Save = new wxButton(Panel1, ID_Save, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Save"));
    Save->SetMinSize(wxSize(-1,-1));
    BoxSizer1->Add(Save, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Run = new wxButton(Panel1, ID_Run, _("Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Run"));
    Run->SetMinSize(wxSize(-1,-1));
    BoxSizer1->Add(Run, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Run_All = new wxButton(Panel1, ID_Run_All, _("RunAll"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Run_All"));
    BoxSizer1->Add(Run_All, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel1);
    FlexGridSizer1->SetSizeHints(Panel1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, ID_MenuNew, _("New db\tAlt-N"), _("Create a new data base"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, idMenuLoad, _("Load db\tAlt-L"), _("Load a data Base"), wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuConfig = new wxMenuItem(Menu3, ID_Config, _("Config\tAlt-F7"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuConfig);
    MenuItem5 = new wxMenuItem(Menu3, ID_Lib, _("Libraries\tAlt-F10"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem5);
    MenuBar1->Append(Menu3, _("&Setup"));
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
    wxString __wxMultiChoiceDialogChoices_1[11] =
    {
    	_("float.h"),
    	_("math.h"),
    	_("stdbool.h"),
    	_("signal.h"),
    	_("stdarg.h"),
    	_("stddef.h"),
    	_("stdint.h"),
    	_("tgmath.h"),
    	_("time.h"),
    	_("wchar.h"),
    	_("windows.h")
    };
    MultiChoiceDialog1 = new wxMultiChoiceDialog(this, _("Select items"), wxEmptyString, 11, __wxMultiChoiceDialogChoices_1, wxCHOICEDLG_STYLE, wxDefaultPosition);

    Connect(ID_LISTBOX,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&SQLManagerFrame::OnListBoxDClick);
    Connect(ID_LISTCTRL,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&SQLManagerFrame::OnlistCtrlItemActivated);
    Connect(ID_LISTCTRL,wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&SQLManagerFrame::OnlistCtrlItemRClick);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SQLManagerFrame::OnParametersText);
    Connect(ID_RADIOBOX,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnRadioBox1Select);
    Connect(ID_BigBox,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SQLManagerFrame::OnTextCtrl1Text);
    Connect(ID_deleteitem,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::OnDeleteClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::LoadFile);
    Connect(ID_Save,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::OnSaveClick);
    Connect(ID_Run,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::OnRunClick);
    Connect(ID_Run_All,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::OnRun_AllClick);
    Connect(ID_MenuNew,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnMenuNewSelected);
    Connect(idMenuLoad,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnMenuLoadSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnQuit);
    Connect(ID_Config,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnMenuConfigSelected);
    Connect(ID_Lib,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnMenuLibrariesSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnAbout);
    //*)

    db =0;
    FilePath=TEXT("SQLDLL.dll");
    CreateDirectoryW(FilePath.c_str(), NULL);
    selected=-1;
    Parameters->SetEditable(0);
    BigBox->SetEditable(0);
    RadioBox->Enable(false);

    listCtrl->InsertColumn(0,"Name");
    listCtrl->InsertColumn(1,"Type");
    listCtrl->InsertColumn(2,"Array");
    listCtrl->InsertColumn(3,"Value");
    retstatus=false;
    for(int n=0;n<11;n++) MultiChoiceDialogChoices_1[n]=__wxMultiChoiceDialogChoices_1[n];

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
    if (first.joinable())
        first.join();
    sqlite3_close(db);
    FreeLibrary(histDLL);
    wxWindow::Destroy(); //The problem come when we overwrite this method or kind of. In that case we need to destroy the window ourself.

}

//Description:
//Function compatible with sqlite3 callback in c++
//This function is used when we want one row items back.
// Parameters are:
//      argc -- the number of rows in the resultset
//      argv[] -- the data for each row
//      azColName -- the name of each column
int SQLManagerFrame::c_callback(void* Used, int argc, char **argv, char **azColName)
{
    int i;
    string* cont = static_cast<string*>(Used);
    if(argc==0)
        return 0;
    for(i=0; i<(argc); i++)
        {
            *cont=*cont+(i!=(argc-1)?(string(argv[i])+" "):string(argv[i]));
        }
return 0;

}
//Description:
//Function compatible with sqlite3 callback in c++
//This function is used when we want different row items back.
// Parameters are:
//      argc -- the number of rows in the resultset
//      argv[] -- the data for each row
//      azColName -- the name of each column
int SQLManagerFrame::c_callback2(void* Used, int argc, char **argv, char **azColName)
{
    string* cont = static_cast<string*>(Used);
    if(argc==0)
        return 0;
    *cont=*cont+string(argv[0])+ " ";
    return 0;

}
/**
*   Description: Load histDLL attribute
*   Parms: void
*   Return: void
**/
void SQLManagerFrame::LoadDll()
{
    histDLL= LoadLibrary(FilePath.c_str());
}
/**
*   Description: Free histDLL attribute
*   Parms: void
*   Return: void
**/
void SQLManagerFrame::FreeDll()
{
    FreeLibrary(histDLL);
}
/**
*   Description: Convert data into string
*   Parms: T
*   Return: string
**/
template<class T>
string SQLManagerFrame::toString(T data)
{
    std::stringstream ss;
    ss << data;
    return ss.str();
}

/**
*   Description:Get a row from db
*   Parms: const char*, const char*,const char*.
*   Return: void
**/
string SQLManagerFrame::lb_reload(const char* tbname, const char* tcname, int id )
{
    Getrow mifunc(0);
    string answer;
    string  num=toString(id);
    LoadDll();
    try
    {
        mifunc=(Getrow)GetProcAddress(histDLL,"row");
        (mifunc)(db,tbname,tcname,num.c_str(),c_callback,&answer );
    }
    catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }
    FreeDll();
    return answer;
    }

/**
*   Description: Get the number of members in a column
*   Parms: string
*   Return: int
**/
int SQLManagerFrame::cont_col(string tbname)
{
    string answer;
    int result;
    Nrow mifunc5(0);
    LoadDll();
    try
    {
        mifunc5=(Nrow)GetProcAddress(histDLL,"n_row");
        result=(mifunc5)(db,tbname.c_str(),c_callback,&answer );
     }
    catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }
    FreeDll();
    result = atoi(answer.c_str());
    return result;
}

/**
*   Description: Pops up a Filedialog windows and call de DLL and create a new database, it can overwrite files.
*   Parms: An Event
*   Return: void
**/
void SQLManagerFrame::OnMenuNewSelected(wxCommandEvent& event)
{
    wxFileDialog  SaveFileDialog(this, _("Save db file"), "", "",
                       "*.db", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    Createbase mifunc(0);
    struct stat info;
    CreateTable mifunc3(0);
    const char* tbname="datos";
      if(selected!=-1&&(BigBox->IsModified()||Parameters->IsModified()||retstatus))
        {
            wxMessageDialog *dial = new wxMessageDialog(NULL
                ,string("The file has been modify, do you want to save your changes: " +ListBox->GetString(selected).ToStdString() )
                                            ,wxT("Save"), wxYES_NO);
            if(dial->ShowModal()==wxID_YES)
                {
                    OnSaveClick(event);
                }
        }
    if (SaveFileDialog.ShowModal() != wxID_OK)
        return;
    const char *dbname=SaveFileDialog.GetPath().ToStdString().c_str();
    LoadDll();
    if(db!=0)
        {
            sqlite3_close(db);
        }
    if( !stat(dbname,&info)&&remove(dbname) != 0 )
        {
            excep_dialog( "Error deleting file" );
            return;
        }
    try
        {
            mifunc=(Createbase)GetProcAddress(histDLL,"CreateDatabase");
            (mifunc)(&db,dbname);
            mifunc3=(CreateTable)GetProcAddress(histDLL,"CreateTable");
            (mifunc3)(db,tbname);
        }
    catch (std::exception& e)
        {
            excep_dialog(string(e.what()));
        }
    FreeDll();
    ClearAll();
    ListBox->Append("New");
    selected=-1;
    BigBoxSetStatus();

}

/**
*   Description: Pops up a dialog windows showing an exception or error
*   Parms: string
*   Return: void
**/
void SQLManagerFrame::excep_dialog(string e)
{
    wxMessageDialog *dial = new wxMessageDialog(NULL,e, wxT("Exception"), wxOK| wxICON_ERROR);
    dial->ShowModal();
}
/**
*   Description: Check if there is any forbidden char for windows system
*   Parms: string
*   Return: bool
**/
bool SQLManagerFrame::str_controler(string String)
{
    int cont=String.find('@')+String.find('\'')+String.find('$')+String.find('%')+String.find('(')
                    +String.find(')')+String.find('¬')+String.find('&')+String.find('#')+String.find('~')
                        +String.find('\\')+String.find('=')+String.find('/')+String.find(':')+String.find('*')
                            +String.find('?')+String.find('"')+String.find('<')+String.find('>')+String.find('|')
                                +String.find('+')+String.find(' ')+String.find('.')+String.find('?')+String.find('[')
                                    +String.find(']');
    if(cont!=-26)
        {
            wxMessageDialog *dial = new wxMessageDialog(NULL, _("Can not use @()#~¬&%$=\\/*:?¿[]\" '<.>|+"),
                                                                 wxT("Unallowed operation"), wxOK | wxICON_EXCLAMATION);
            dial->ShowModal();
            return true;
        }
    return false;
}
/**
*   Description: Insert text in the big box. It also delete the one before.
*   Parms: string
*   Return: void
**/
void SQLManagerFrame::insert_text_BB(string text)
{
    BigBox->Clear();
    BigBox->SetForegroundColour(wxColour(0,0,0));
    BigBox->AppendText(text);
}
/**
*   Description: Insert text in the Parameter box.
*   Parms: string
*   Return: void
**/
void SQLManagerFrame::insert_text_P(string text)
{
    Parameters->Clear();
    Parameters->SetForegroundColour(wxColour(0,0,0));
    Parameters->AppendText(text);
}

/**
*   Description: clear text in the big box and listbox.
*   Parms: void
*   Return: void
**/
void SQLManagerFrame::ClearAll()
{
    BigBox->Clear();
    Parameters->Clear();
    ListBox->Clear();
    listCtrl->DeleteAllItems();
}

/**
*   Description: Pops up a Filedialog windows and call de DLL and open a new database
*   Parms: An Event
*   Return: void
**/
void SQLManagerFrame::OnMenuLoadSelected(wxCommandEvent& event)
{   int i;
    int result;
    wxString str;
    Createbase mifunc(0);
    if(selected!=-1&&(BigBox->IsModified()||Parameters->IsModified()||retstatus))
        {
            wxMessageDialog *dial = new wxMessageDialog(NULL
                ,string("The file has been modify, do you want to save your changes: " +ListBox->GetString(selected).ToStdString() )
                                            ,wxT("Save"), wxYES_NO);
            if(dial->ShowModal()==wxID_YES)
                {
                    OnSaveClick(event);
                }
        }

    wxFileDialog OpenFileDialog(this, _("Open db file"), "", "","*.db", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    result=OpenFileDialog.ShowModal();
    if(result!=wxID_OK)
        return;
    const char* dbname=OpenFileDialog.GetPath().ToStdString().c_str();
    LoadDll();
    try
        {
            mifunc=(Createbase)GetProcAddress(histDLL,"CreateDatabase");
            result=(mifunc)(&db,dbname);
        }
    catch (std::exception& e)
        {
            excep_dialog(string(e.what()));
        }
    FreeDll();
    if(result!=0)
        {
            return;
        }
    ClearAll();
    result=cont_col("datos");
    for(i=0;i<result;i++)
        {
            str=lb_reload("datos","name",i);
            if (str.Len() > 0)
            ListBox->Append(str);
        }
    ListBox->Append("New");
    selected=-1;
    BigBoxSetStatus();

}

/**
*   Description: We set the real selection of the listbox when we are going to type in a textbox.
*   Parms: An Event
*   Return: void
**/
void SQLManagerFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
    if(selected==-1)
        return;
    ListBox->SetSelection(selected);
}

/**
*   Description: Blocks the textboxs if there is none selected item in the listbox.
*   Parms: An Event
*   Return: void
**/
void SQLManagerFrame::BigBoxSetStatus()
{
    if(selected==-1)
        {
            RadioBox->Enable(false);
            Parameters->SetEditable(0);
            BigBox->SetEditable(0);
            return;
        }
     RadioBox->Enable(true);
     Parameters->SetEditable(1);
     BigBox->SetEditable(1);
}
/**
*   Description:
*   Parms: string,string
*   Return: void
**/
void SQLManagerFrame::FillListCtrl(string answer,string resp)
{
    string answer2=answer;
    string container;
    Getitem getitem(0);
    string delimiters = " ";
    size_t current;
    size_t next = -1;
    int i=0;
        do
            {
                current = next + 1;
                next = answer2.find_first_of(delimiters, current );
                answer=std::string();
                container=answer2.substr( current, next - current );
                listCtrl->InsertItem(i,"n");
                getitem=(Getitem)GetProcAddress(histDLL,"get_item");
                listCtrl->SetItem(i,0,container);
                (getitem)(db,"params","type","name",container.c_str(),resp.c_str(),c_callback,&answer );
                listCtrl->SetItem(i,1,answer);
                answer=std::string();
                getitem=(Getitem)GetProcAddress(histDLL,"get_item");
                (getitem)(db,"params","array","name",container.c_str(),resp.c_str(),c_callback,&answer );
                listCtrl->SetItem(i,2,answer);
                answer=std::string();
                getitem=(Getitem)GetProcAddress(histDLL,"get_item");
                (getitem)(db,"params","value","name",container.c_str(),resp.c_str(),c_callback,&answer );
                listCtrl->SetItem(i,3,answer);
                i++;
            }while (next != string::npos);

    listCtrl->SetItem(i-1,0,"New");
}

void SQLManagerFrame::OnListBoxDClick(wxCommandEvent& event)
{
    string answer;
    string resp;
    Getrow getrow(0);
    add_item additem(0);
    wxString text;
    wxString renamed;
    int posR;
    int sel = ListBox->GetSelection();
    if (sel == -1)
        {
        return;
        }
    else if(ListBox->GetCount()==((unsigned int)sel+1))
        {
        text ="New item";
         if(BigBox->IsModified()||Parameters->IsModified()||retstatus)
                {
                wxMessageDialog *dial = new wxMessageDialog(NULL
                                                            ,string("The file has been modify, do you want to save your changes: " +ListBox->GetString(selected).ToStdString() )
                                                            ,wxT("Save"), wxYES_NO);
                if(dial->ShowModal()==wxID_YES)
                    {
                    OnSaveClick(event);
                    }

                }

        do{
            wxTextEntryDialog  myDialog(this, _("Name of the item"), _("New item"), _(""));
            myDialog.SetMaxLength(30);
            if ( myDialog.ShowModal() != wxID_OK )
                {
                        return;
                }
        renamed = myDialog.GetValue();

        //renamed = wxGetTextFromUser(wxT("Name of the item"),wxT("New item"), text);
        }while(renamed.IsSameAs("new")||renamed.IsSameAs("New")||renamed.IsSameAs("NEW")||str_controler(renamed.ToStdString()));

        if (renamed.IsEmpty()||wxNOT_FOUND!=ListBox->FindString(renamed))
            {
                wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Can not repeat names neither leave it blank"),
                                                             wxT("Unallowed operation"), wxOK | wxICON_EXCLAMATION);
                dial->ShowModal();
                return;
            }
            ListBox->Delete(sel);
            ListBox->Insert(renamed, sel);
            ListBox->Append("New");
            LoadDll();
            try

                {
                    additem=(add_item)GetProcAddress(histDLL,"add_item");
                    (additem)(db,"datos","name",renamed.ToStdString().c_str());
                }
            catch (std::exception& e)
                {
                    excep_dialog(string(e.what()));
                }
            selected=sel;
            ListBox->SetSelection(selected);
            text = ListBox->GetString(selected);
          try
            {
                getrow=(Getrow)GetProcAddress(histDLL,"id_row");
                (getrow)(db,"datos","name",text.ToStdString().c_str(),c_callback,&resp);
                getrow=(Getrow)GetProcAddress(histDLL,"row");
                (getrow)(db,"datos","parms",resp.c_str(),c_callback,&answer );
            }
            catch (std::exception& e)
            {
                excep_dialog(string(e.what()));
            }
            FreeDll();
            insert_text_P(answer);
            listCtrl->DeleteAllItems();
            listCtrl->InsertItem(0,"New");
            BigBox->SetModified(0);
            Parameters->SetModified(0);
            RadioBox->SetSelection(0);
        }
    else
        {
            if(selected==sel)
                return;
            if(BigBox->IsModified()||Parameters->IsModified()||retstatus)
                {
                wxMessageDialog *dial = new wxMessageDialog(NULL
                                                            ,string("The file has been modify, do you want to save your changes: " +ListBox->GetString(selected).ToStdString() )
                                                            ,wxT("Save"), wxYES_NO);
                if(dial->ShowModal()==wxID_YES)
                    {
                    OnSaveClick(event);
                    }

                }
            text = ListBox->GetString(sel);
            LoadDll();
            try
                {
                getrow=(Getrow)GetProcAddress(histDLL,"id_row");
                (getrow)(db,"datos","name",text.ToStdString().c_str(),c_callback,&resp);
                getrow=(Getrow)GetProcAddress(histDLL,"row");
                (getrow)(db,"datos","ref",resp.c_str(),c_callback,&answer );
                }
            catch (std::exception& e)
                {
                excep_dialog(string(e.what()));
                }
            selected=sel;
            insert_text_BB(answer);
            try
                {
                answer=std::string();
                getrow=(Getrow)GetProcAddress(histDLL,"row");
                (getrow)(db,"datos","parms",resp.c_str(),c_callback,&answer );
                }
            catch (std::exception& e)
                {
                excep_dialog(string(e.what()));
                }
            insert_text_P(answer);

            try
                {   listCtrl->DeleteAllItems();
                    answer=std::string();
                    getrow=(Getrow)GetProcAddress(histDLL,"row");
                    (getrow)(db,"params","name",resp.c_str(),c_callback2,&answer );
                    FillListCtrl(answer,resp);

                }
            catch (std::exception& e)
                {
                    excep_dialog(string(e.what()));
                }

                 try
                {
                    answer=std::string();
                    getrow=(Getrow)GetProcAddress(histDLL,"row");
                    (getrow)(db,"datos","ret",resp.c_str(),c_callback,&answer );
                }
            catch (std::exception& e)
                {
                excep_dialog(string(e.what()));
                }

            FreeDll();
            posR=RadioBox->FindString(answer);
            if(posR!=wxNOT_FOUND)
                RadioBox->SetSelection(posR);
            BigBox->SetModified(0);
            Parameters->SetModified(0);
            if(RadioBox->GetSelection()==0)
                Parameters->Enable(0);
            else
                Parameters->Enable(1);
        }
    BigBoxSetStatus();

}


void SQLManagerFrame::OnDeleteClick(wxCommandEvent& event)
{
    Getrow getid(0);
    string resp;
    wxString text;
    wxString renamed;
    add_item delitem(0);
    if(selected==-1)
        {
        return;
        }

    text = ListBox->GetString(selected);
    wxMessageDialog *dial = new wxMessageDialog(NULL,string("Are you sure you want to delete: " +text ), wxT("Delete"),wxICON_EXCLAMATION| wxYES_NO);
    if(dial->ShowModal()==wxID_NO)
        return;
    LoadDll();
    try
    {
        getid=(Getrow)GetProcAddress(histDLL,"id_row");
        (getid)(db,"datos","name",text.ToStdString().c_str(),c_callback,&resp);
        delitem=(add_item)GetProcAddress(histDLL,"del_item");
        (delitem)(db,"datos",resp.c_str(),"id");
        ListBox->Delete(selected);
     }catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }
    FreeDll();
    BigBox->Clear();
    listCtrl->DeleteAllItems();
    selected=-1;
    BigBoxSetStatus();
}

void SQLManagerFrame::OnSaveClick(wxCommandEvent& event)
{
    int i;
    add_text addtext(0);
    Getrow getid(0);
    string resp;
    string text;
    if(selected==-1)
        return;
    string name=ListBox->GetString(selected).ToStdString().c_str();
    if(event.GetId()==ID_Save)
    {
    wxMessageDialog *dial = new wxMessageDialog(NULL,string("Are you sure you want to overwrite: " +name ), wxT("Save"), wxYES_NO);
    if(dial->ShowModal()==wxNO)
        return;

    }

    text="";
    int n_lines=BigBox->GetNumberOfLines();
    for(i=0;i<n_lines;i++)
        {
            if(i==(n_lines-1))
            {
                text=text+BigBox->GetLineText(i).ToStdString();
                break;
            }
            text=text+BigBox->GetLineText(i).ToStdString()+"\n";
        }
    LoadDll();
    try
    {
        getid=(Getrow)GetProcAddress(histDLL,"id_row");
        (getid)(db,"datos","name",name.c_str(),c_callback,&resp);
        addtext=(add_text)GetProcAddress(histDLL,"add_text");
        (addtext)(db,"datos","ref",text.c_str(),"id",resp.c_str());
        text=Parameters->GetLineText(0).ToStdString()==std::string()?" ":Parameters->GetLineText(0).ToStdString();
        addtext=(add_text)GetProcAddress(histDLL,"add_text");
        (addtext)(db,"datos","parms",text.c_str(),"id",resp.c_str());
        text=RadioBox->GetStringSelection().ToStdString()==std::string()?"void":RadioBox->GetStringSelection().ToStdString();
        addtext=(add_text)GetProcAddress(histDLL,"add_text");
        (addtext)(db,"datos","ret",text.c_str(),"id",resp.c_str());

     }catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }
    /**int nlistC=(listCtrl->GetItemCount ()-1);
    try
    {   for(i=0;nlistC>i;i++)
            {
            // update
            addparams=(add_params)GetProcAddress(histDLL,"add_params");
            (addparams)(db,"params","id,name,type,value",resp.c_str(),listCtrl->GetItemText(i,0).c_str().AsChar(),listCtrl->GetItemText(i,1).c_str().AsChar(),listCtrl->GetItemText(i,2).c_str().AsChar());
            }
     }catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }*/
    FreeDll();
    BigBoxSetStatus();
    BigBox->SetModified(0);
    Parameters->SetModified(0);
    retstatus=false;

}

void SQLManagerFrame::OnRunClick(wxCommandEvent& event)
{
    string resp;
    string answer;
    string renamed;
    string code;
    string parm;
    string headfuncs;
    string libs;
    string ret;
    Params result;
    wxArrayInt selections;
    Getrow getrow(0);
    Getitem getitem(0);
    if(selected==-1)
        return;
    if(BigBox->IsModified()||Parameters->IsModified()||retstatus)
        {
        wxMessageDialog *dial = new wxMessageDialog(NULL,string("Before running, you need to save it: " +ListBox->GetString(selected).ToStdString() ), wxT("Delete"), wxYES_NO);
        if(dial->ShowModal()==wxID_NO)
            return;

        OnSaveClick(event);
        }
    string text = ListBox->GetString(selected).ToStdString();

        LoadDll();
    try
    {
        getitem=(Getitem)GetProcAddress(histDLL,"get_item");
        (getitem)(db,"config","name","id","1","1",c_callback,&renamed );
    }
        catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }

    FreeDll();
    if((renamed==std::string())||!(renamed.find_first_not_of(' ') != std::string::npos))
    {
        renamed=std::string();
    do{
            wxTextEntryDialog  myDialog(this, _("Name of the file output"), _("New item"), _(""));
            myDialog.SetMaxLength(30);
            if ( myDialog.ShowModal() != wxID_OK )
                {
                        return;
                }
        renamed = myDialog.GetValue().ToStdString();
    }while(str_controler(renamed));
     if (renamed==std::string())
            {
                wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Can not leave it blank"),
                                                             wxT("Unallowed operation"), wxOK | wxICON_EXCLAMATION);
                dial->ShowModal();
                return;
            }
    }
    LoadDll();
    try
    {
            getrow=(Getrow)GetProcAddress(histDLL,"id_row");
            (getrow)(db,"datos","name",text.c_str(),c_callback,&resp);
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","ref",resp.c_str(),c_callback,&code );
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","ret",resp.c_str(),c_callback,&ret );
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","parms",resp.c_str(),c_callback,&parm );
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"params","name",resp.c_str(),c_callback2,&answer );
    }
    catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }
    result=GetParams(answer,resp,0);
    headfuncs=ret+" __stdcall FUNCTION_DLL "+text+"("+result.cont+");";
  //  code=" __stdcall "+ret+" "+text +"("+GetParams()+")\n{\n"+code+"\n}";
    code=" __stdcall "+ret+" "+text +"("+GetParams(answer,resp,1).cont+")\n{\n"+((ret=="void")?"":(ret+" "+parm+";\n"))+code+"\n"+(ret!="void"?("return "+parm+";"):" ")+"\n}\n";
     try
        {
            getitem=(Getitem)GetProcAddress(histDLL,"get_item");
            (getitem)(db,"config","libs","id","1","1",c_callback,&answer );
        }
    catch (std::exception& e)
        {
            excep_dialog(string(e.what()));
        }
    FreeDll();
    if (answer!="-1")
        {
            string delimiters = ",";
            size_t current;
            size_t next = -1;
            do
                {
                    current = next + 1;
                    next = answer.find_first_of(delimiters, current );
                    selections.Add(atoi(answer.substr( current, next - current ).c_str()));
                }while (next != string::npos);
            for (size_t n=0; n < selections.GetCount(); ++n )
            libs=libs+("#include <"+MultiChoiceDialogChoices_1[selections[n]])+ ">\n";
        }


    GenerateDllFiles_v2(renamed,code,headfuncs,libs);
    TesterDialog mi(this);
    mi.GenerateGrid(result.num,1);
    mi.ColorSet(result.mytypes,0);
    mi.RowName(text,0);
    mi.ShowModal();
    first.join();

}

void SQLManagerFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

 SQLManagerFrame::Params SQLManagerFrame::GetParams(string answer,string resp,int n)
{   std::list<string> mytypes;
    Params result;
    string answer2=answer.substr(0,answer.length()-1);
    string cont;
    string type;
    string isarray;
    string container;
    Getitem getitem(0);
    string delimiters = " ";
    size_t current;
    size_t next = -1;
    int i=0;

        do
            {
                current = next + 1;
                next = answer2.find_first_of(delimiters, current );
                answer=std::string();
                container=answer2.substr( current, next - current );
                getitem=(Getitem)GetProcAddress(histDLL,"get_item");
                (getitem)(db,"params","type","name",container.c_str(),resp.c_str(),c_callback,&type );

                cont=cont+type+" "+container;
                getitem=(Getitem)GetProcAddress(histDLL,"get_item");
                (getitem)(db,"params","array","name",container.c_str(),resp.c_str(),c_callback,&isarray );
                answer=std::string();
                getitem=(Getitem)GetProcAddress(histDLL,"get_item");
                (getitem)(db,"params","value","name",container.c_str(),resp.c_str(),c_callback,&answer);
                if (isarray=="1"&&answer!="")
                    answer=array_maker(answer,type);
                if(answer!=""&&n==0)
                    {
                    cont=cont+((isarray=="1")?"[]":"")+"="+answer+",";
                }else{
                    cont=cont+((isarray=="1")?"[]":"")+",";
                }
                if(type!=std::string())
                    mytypes.push_back(type);
                type=std::string();
                isarray=std::string();
                i++;
            }while (next != string::npos);
            cont=(cont.length()!=0)?cont.substr(0,cont.length()-1):"";
            result.cont=cont;
            result.num=mytypes.size();
            result.mytypes=mytypes;
return result;
}

void SQLManagerFrame::OnPanel1Paint1(wxPaintEvent& event)
{
}
string SQLManagerFrame::array_maker(string arraypar,string type)
{

    string cont="("+type+"[]){"+arraypar+"}";
   /** string delimiters = ",";
    size_t current;
    size_t next = -1;
    do
    {
    current = next + 1;
    next = arraypar.find_first_of(delimiters, current );
    cont=cont+arraypar.substr( current, next - current )+";";
    }while (next != string::npos);
    cont=cont.substr(0,cont.length()-1)+"}";*/
    return cont;
}

void SQLManagerFrame::LoadFile(wxCommandEvent& event)
{
}


void SQLManagerFrame::OnRun_AllClick(wxCommandEvent& event)
{
    max_params MaxParms(0);
    string resp;
    string answer;
    string renamed;
    string code;
    string code_cont;
    string headfuncs;
    string parm;
    string text;
    string libs_cont;
    string ret;
    TesterDialog mi(this);
    Params result;
    int n_items;
    int i;
    Getrow getrow(0);
    Getitem getitem(0);
     if(db==0)
        return;
    if(BigBox->IsModified()||Parameters->IsModified()||retstatus)
        {
        wxMessageDialog *dial = new wxMessageDialog(NULL,string("Before running, you need to save it: " +ListBox->GetString(selected).ToStdString() ), wxT("Delete"), wxYES_NO);
        if(dial->ShowModal()==wxID_NO)
            return;
        OnSaveClick(event);
        }
    LoadDll();
    try
    {
        getitem=(Getitem)GetProcAddress(histDLL,"get_item");
        (getitem)(db,"config","name","id","1","1",c_callback,&renamed );
    }
        catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }

    FreeDll();
    if((renamed==std::string())||!(renamed.find_first_not_of(' ') != std::string::npos))
    {
        renamed=std::string();
    do{
            wxTextEntryDialog  myDialog(this, _("Name of the file output"), _("New item"), _(""));
            myDialog.SetMaxLength(30);
            if ( myDialog.ShowModal() != wxID_OK )
                {
                        return;
                }
        renamed = myDialog.GetValue().ToStdString();
    }while(str_controler(renamed));

     if (renamed==std::string())
            {
                wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Can not leave it blank"),
                                                             wxT("Unallowed operation"), wxOK | wxICON_EXCLAMATION);
                dial->ShowModal();
                return;
            }
    }
    LoadDll();
    try
    {
        MaxParms=(max_params)GetProcAddress(histDLL,"max_parms");
        (MaxParms)(db,"params","id",c_callback,&answer );
    }
        catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }
    n_items=cont_col("datos");
    mi.GenerateGrid(atoi(answer.c_str()),n_items-1);
    answer=std::string();
    for(i=0;(i)<n_items;i++)
        {
            text=lb_reload("datos","name",i);
            if (text.length() > 0)
            {
                 try
                 {
                    getrow=(Getrow)GetProcAddress(histDLL,"id_row");
                    (getrow)(db,"datos","name",text.c_str(),c_callback,&resp);
                    getrow=(Getrow)GetProcAddress(histDLL,"row");
                    (getrow)(db,"datos","ref",resp.c_str(),c_callback,&code );
                    getrow=(Getrow)GetProcAddress(histDLL,"row");
                    (getrow)(db,"datos","ret",resp.c_str(),c_callback,&ret );
                    getrow=(Getrow)GetProcAddress(histDLL,"row");
                    (getrow)(db,"datos","parms",resp.c_str(),c_callback,&parm );
                    getrow=(Getrow)GetProcAddress(histDLL,"row");
                    (getrow)(db,"params","name",resp.c_str(),c_callback2,&answer );
                    result=GetParams(answer,resp,0);
                    headfuncs=headfuncs+ret+" __stdcall FUNCTION_DLL "+text+"("+result.cont+");\n";
                    code_cont=code_cont+" __stdcall FUNCTION_DLL "+ret+" "+text +"("+GetParams(answer,resp,1).cont+")\n{\n"+((ret=="void")?"":(ret+" "+parm+";\n"))+code+"\n"+(ret!="void"?("return "+parm+";"):" ")+"\n}\n";
                    mi.ColorSet(result.mytypes,i-1);
                    mi.RowName(text,i-1);

                    resp=std::string();
                    code=std::string();
                    ret=std::string();
                    answer=std::string();
                    parm=std::string();
                }
                catch (std::exception& e)
                {
                    excep_dialog(string(e.what()));
                }

            }

        }

    FreeDll();
    wxArrayInt selections=MultiChoiceDialog1->GetSelections();
    for (size_t n=0; n < selections.GetCount(); ++n )
            libs_cont=libs_cont+("#include <"+MultiChoiceDialogChoices_1[selections[n]])+ ">\n";
    GenerateDllFiles_v2(renamed,code_cont,headfuncs,libs_cont,n_items);
    mi.ShowModal();
    first.join();

}
void SQLManagerFrame:: GenerateDllFiles_v2(string N_file,string code, string headfuncs,string libs,int N)
{
    std::ofstream myfile;
    char *H_file =(char*) malloc((N*30*sizeof(char)+400*sizeof(char)));
    sprintf(H_file,"#ifndef __%s_H__\n#define __%s_H__\n#ifdef BUILDING_DLL\n#define FUNCTION_DLL __declspec(dllexport)\n#else\n#define FUNCTION_DLL __declspec(dllimport)\n#endif\n\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n %s\n#ifdef __cplusplus\n}\n#endif\n#endif"
            ,N_file.c_str(),N_file.c_str(),headfuncs.c_str());
    string cont="Dll_release\\"+N_file+".h";
    CreateDirectory(L"Dll_release",NULL);
    myfile.open (cont.c_str());
    myfile << H_file;
    myfile.close();
    free(H_file);
    char C_file[600];
    sprintf(C_file,"#include \"%s.h\"\n#include <stdio.h>\n%s\n "
            ,N_file.c_str(),libs.c_str());
    cont="Dll_release\\"+N_file+".cpp";
    myfile.open (cont.c_str());
    myfile << C_file << code <<"extern \"C\" FUNCTION_DLL BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)\n{\n    switch (fdwReason)\n    {\n        case DLL_PROCESS_ATTACH:\n            // attach to process\n            // return FALSE to fail DLL load\n            break;\n        case DLL_PROCESS_DETACH:\n            // detach from process\n            break;\n        case DLL_THREAD_ATTACH:\n            // attach to thread\n            break;\n        case DLL_THREAD_DETACH:\n            // detach from thread\n            break;\n    }\n    return TRUE; // succesful\n}";
        myfile.close();
    char *command =(char*) malloc((3*30*sizeof(char)+900*sizeof(char)));
    sprintf(command,"(g++ -Wall -DBUILDING_DLL -O2  -c Dll_release\\%s.cpp -o Dll_release\\%s.o || pause )& g++ -shared -Wl,--output-def=Dll_release\\%s.def -Wl,--out-implib=Dll_release\\%s.a -Wl,--dll  Dll_release\\%s.o  -o Dll_release\\%s.dll -s "
            ,N_file.c_str(),N_file.c_str(),N_file.c_str(),N_file.c_str(),N_file.c_str(),N_file.c_str());
    /**if (first.joinable())
    first.join();if (first.joinable())
    first.join();*/
    first=std::thread (system,command);

  //  int consta=system("exit(1)");
//    free(command);
}

void SQLManagerFrame::OnLibrariesText(wxCommandEvent& event)
{
}

void SQLManagerFrame::OnRadioBox1Select(wxCommandEvent& event)
{
    retstatus=true;
    if(RadioBox->GetSelection()==0)
        Parameters->Enable(0);
    else
        Parameters->Enable(1);
}

void SQLManagerFrame::OnParametersText(wxCommandEvent& event)
{
}

void SQLManagerFrame::OnListViewBeginDrag(wxListEvent& event)
{
}

void SQLManagerFrame::OnlistCtrlItemActivated(wxListEvent& event)
{
    string resp;
    Getrow getid(0);
    add_params addparams(0);
    add_text addtext(0);
    int n=listCtrl->GetItemCount ();
    int sel=event.GetIndex();
    if(sel==-1)
        return;
    else if(n==(sel+1))
        {
            CParams mi(this);
            if(mi.ShowModal()==wxID_CANCEL)
                return;
            if(listCtrl->FindItem(0,mi.GetName())!=wxNOT_FOUND)
            {
                  wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Can not repeat names neither leave it blank"),
                     wxT("Unallowed operation"), wxOK | wxICON_EXCLAMATION);
                    dial->ShowModal();
                    return;
            }
            listCtrl->SetItem(sel,0, mi.GetName());
            listCtrl->SetItem(sel,1, mi.GetType());
            listCtrl->SetItem(sel,2, mi.GetArray()?"1":"0");
            listCtrl->SetItem(sel,3, mi.GetDefault());
            listCtrl->InsertItem((sel+1),"New");
            LoadDll();
            try
            {
                getid=(Getrow)GetProcAddress(histDLL,"id_row");
                (getid)(db,"datos","name",ListBox->GetString(selected).ToStdString().c_str(),c_callback,&resp);
                addparams=(add_params)GetProcAddress(histDLL,"add_params");
                (addparams)(db,"params","id,name,type,value,array",resp.c_str(),mi.GetName().c_str(),mi.GetType().c_str(),mi.GetDefault().c_str(),mi.GetArray()?"1":"0");

            }
            catch (std::exception& e)
            {
                    excep_dialog(string(e.what()));
            }
            FreeDll();

 //   wxMessageBox("Selected index: "+wxString()<<n, "Selection Changed!",wxOK);
        }
        else
            {
                CParams mi(this);
                mi.SetDefault(listCtrl->GetItemText(sel,3).ToStdString());
                mi.SetArray(listCtrl->GetItemText(sel,2).ToStdString()=="1");
                mi.SetName(listCtrl->GetItemText(sel,0).ToStdString());
                mi.SetType(listCtrl->GetItemText(sel,1).ToStdString());
                LoadDll();
                try
                {
                if(mi.ShowModal()==wxID_CANCEL)
                    return;
                addtext=(add_text)GetProcAddress(histDLL,"add_text");
                (addtext)(db,"params","type",mi.GetType().c_str(),"name",listCtrl->GetItemText(sel,0).ToStdString().c_str());
                addtext=(add_text)GetProcAddress(histDLL,"add_text");
                (addtext)(db,"params","value",mi.GetDefault().c_str(),"name",listCtrl->GetItemText(sel,0).ToStdString().c_str());
                addtext=(add_text)GetProcAddress(histDLL,"add_text");
                (addtext)(db,"params","array",mi.GetArray()?"1":"0","name",listCtrl->GetItemText(sel,0).ToStdString().c_str());
                addtext=(add_text)GetProcAddress(histDLL,"add_text");
                (addtext)(db,"params","name",mi.GetName().c_str(),"name",listCtrl->GetItemText(sel,0).ToStdString().c_str());
                }
                catch (std::exception& e)
                {
                    excep_dialog(string(e.what()));
                }
                FreeDll();
                listCtrl->SetItem(sel,0, mi.GetName());
                listCtrl->SetItem(sel,1, mi.GetType());
                listCtrl->SetItem(sel,2, mi.GetArray()?"1":"0");
                listCtrl->SetItem(sel,3, mi.GetDefault());
            }
   // long list_index=listCtrl->InsertItem(0,"New");
   // listCtrl->SetItem(list_index, 1, L"Text");
}


void SQLManagerFrame::OnlistCtrlItemRClick(wxListEvent& event)
{

    add_item delitem(0);
    int result;
    string selection=event.GetItem().GetText().ToStdString();
 	wxMenu mnu;
    mnu.Append(ID_MODIFYILIST, "Edit");
 	mnu.Append(ID_DELETEILIST, "Delete");
 	result=wxWindow::GetPopupMenuSelectionFromUser(mnu);
    switch(result)
        {
 		case ID_MODIFYILIST:
 		    SQLManagerFrame::OnlistCtrlItemActivated(event);
 			break;
 		case ID_DELETEILIST:
            wxMessageDialog *dial = new wxMessageDialog(NULL,string("Are you sure you want to delete: " )+selection, wxT("Delete"),wxICON_EXCLAMATION| wxYES_NO);
            if(dial->ShowModal()==wxID_NO)
                return;

            LoadDll();
            try
                {
                    delitem=(add_item)GetProcAddress(histDLL,"del_item");
                    result=(delitem)(db,"params",selection.c_str(),"name");
                }
            catch (std::exception& e)
                {
                    excep_dialog(string(e.what()));
                }
            FreeDll();
            if(result!=0)
                return;
            listCtrl->DeleteItem(event.GetItem().GetId());
            break;
        }

}

void SQLManagerFrame::OnMenuLibrariesSelected(wxCommandEvent& event)
{
    Getitem getitem(0);
    add_text addtext(0);
    wxArrayInt selections;
    string answer;
    if(db==0)
        return;
    LoadDll();
    try
        {
            getitem=(Getitem)GetProcAddress(histDLL,"get_item");
            (getitem)(db,"config","libs","id","1","1",c_callback,&answer );
        }
    catch (std::exception& e)
        {
            excep_dialog(string(e.what()));
        }
    FreeDll();
    if (answer!="-1")
        {
            string delimiters = ",";
            size_t current;
            size_t next = -1;
            do
                {
                    current = next + 1;
                    next = answer.find_first_of(delimiters, current );
                    selections.Add(atoi(answer.substr( current, next - current ).c_str()));
                }while (next != string::npos);
            MultiChoiceDialog1->SetSelections(selections);

        }
    MultiChoiceDialog1->ShowModal();
    selections=MultiChoiceDialog1->GetSelections();
    answer=std::string();
    for (size_t n=0; n < selections.GetCount(); ++n )
            answer=answer+toString(selections[n])+",";

    LoadDll();
    try
        {
            addtext=(add_text)GetProcAddress(histDLL,"add_text");
            (addtext)(db,"config","libs",answer.substr(0,answer.length()-1).c_str(),"id","1");
        }
    catch (std::exception& e)
        {
            excep_dialog(string(e.what()));
        }
    FreeDll();

}

void SQLManagerFrame::OnMenuConfigSelected(wxCommandEvent& event)
{
Getitem getitem(0);
add_text addtext(0);
string answer;
if(db==0)
    return;
ConfigDialog mi(this);
LoadDll();
try
    {
        getitem=(Getitem)GetProcAddress(histDLL,"get_item");
        (getitem)(db,"config","name","id","1","1",c_callback,&answer );
    }
catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }
 FreeDll();

mi.SetName(answer);
if(mi.ShowModal()!=wxID_OK)
    return;
LoadDll();
try
    {
        addtext=(add_text)GetProcAddress(histDLL,"add_text");
        (addtext)(db,"config","name",mi.GetName().c_str(),"id","1");
    }
catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }
FreeDll();
}
