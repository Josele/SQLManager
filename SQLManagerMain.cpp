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
#include <thread>

//(*InternalHeaders(SQLManagerFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)
HINSTANCE histDLL;
//helper functions
//try to work with an array
typedef int (*Createbase) (sqlite3**,const char*);
typedef int (*Callblback)(void*,int,char**,char**);
typedef int (*CreateTable) (sqlite3*,const char*);
typedef int (*add_item) (sqlite3*, const char* ,const char* ,const char* );
typedef int (*add_text) (sqlite3*, const char *,const char *,const char *,const char *);
typedef int (*del_item) (sqlite3*, const char*  ,const char* );
typedef int (*Getrow) (sqlite3* , const char* ,const char*,const char*,int (*callback)(void*,int,char**,char**),void* );
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
const long SQLManagerFrame::ID_STATICTEXT2 = wxNewId();
const long SQLManagerFrame::ID_LISTBOX = wxNewId();
const long SQLManagerFrame::ID_STATICLINE1 = wxNewId();
const long SQLManagerFrame::ID_STATICTEXT4 = wxNewId();
const long SQLManagerFrame::ID_STATICTEXT5 = wxNewId();
const long SQLManagerFrame::ID_STATICTEXT3 = wxNewId();
const long SQLManagerFrame::ID_TEXTCTRL2 = wxNewId();
const long SQLManagerFrame::ID_RADIOBOX = wxNewId();
const long SQLManagerFrame::ID_TEXTCTRL1 = wxNewId();
const long SQLManagerFrame::ID_LISTCTRL = wxNewId();
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
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("Dll_Manager"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(600,450));
    SetMinSize(wxSize(-1,-1));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(288,216), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetMinSize(wxSize(400,-1));
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer1->AddGrowableCol(2);
    FlexGridSizer1->AddGrowableRow(1);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText1->SetMinSize(wxSize(-1,-1));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Code"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText2->SetMinSize(wxSize(-1,-1));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ListBox = new wxListBox(Panel1, ID_LISTBOX, wxDefaultPosition, wxSize(132,224), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX"));
    ListBox->SetMinSize(wxSize(-1,-1));
    FlexGridSizer1->Add(ListBox, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxDefaultPosition, wxSize(1,370), wxLI_VERTICAL, _T("ID_STATICLINE1"));
    StaticLine1->SetMinSize(wxSize(-1,-1));
    FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableCol(1);
    FlexGridSizer2->AddGrowableCol(2);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Params"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer2->Add(StaticText4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Return"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer2->Add(StaticText5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Extra Libraries"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer2->Add(StaticText3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Parameters = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_RICH2, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer2->Add(Parameters, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxString __wxRadioBoxChoices_1[3] =
    {
    	_("void"),
    	_("int"),
    	_("char*")
    };
    RadioBox = new wxRadioBox(Panel1, ID_RADIOBOX, wxEmptyString, wxPoint(-1,-1), wxSize(169,40), 3, __wxRadioBoxChoices_1, 1, wxRA_VERTICAL, wxDefaultValidator, _T("ID_RADIOBOX"));
    RadioBox->SetMinSize(wxSize(-1,-1));
    RadioBox->SetMaxSize(wxSize(-1,-1));
    FlexGridSizer2->Add(RadioBox, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    Libraries = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(-1,-1)), wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_RICH2, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer2->Add(Libraries, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(FlexGridSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    listCtrl = new wxListCtrl(Panel1, ID_LISTCTRL, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_LISTCTRL"));
    BoxSizer3->Add(listCtrl, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BigBox = new wxTextCtrl(Panel1, ID_BigBox, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(532,228)), wxTE_AUTO_SCROLL|wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_MULTILINE|wxTE_RICH2|wxVSCROLL, wxDefaultValidator, _T("ID_BigBox"));
    BigBox->SetMinSize(wxSize(400,-1));
    BoxSizer3->Add(BigBox, 2, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_TOP, 6);
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

    Connect(ID_LISTBOX,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnListBox1Select);
    Connect(ID_LISTBOX,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&SQLManagerFrame::OnListBoxDClick);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SQLManagerFrame::OnParametersText);
    Connect(ID_RADIOBOX,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnRadioBox1Select);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SQLManagerFrame::OnLibrariesText);
    Connect(ID_LISTCTRL,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&SQLManagerFrame::OnlistCtrlItemActivated);
    Connect(ID_BigBox,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SQLManagerFrame::OnTextCtrl1Text);
    Connect(ID_deleteitem,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::OnDeleteClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::LoadFile);
    Connect(ID_Save,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::OnSaveClick);
    Connect(ID_Run,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::OnRunClick);
    Connect(ID_Run_All,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::OnRun_AllClick);
    Connect(ID_MenuNew,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnMenuNewSelected);
    Connect(idMenuLoad,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnMenuLoadSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SQLManagerFrame::OnAbout);
    //*)

    db =0;
    FilePath=TEXT("SQLDLL.dll");
    CreateDirectoryW(FilePath.c_str(), NULL);
    selected=-1;
    Parameters->SetEditable(0);
    Libraries->SetEditable(0);
    BigBox->SetEditable(0);

    listCtrl->InsertColumn(0,"Name");
    listCtrl->InsertColumn(1,"Type");
    listCtrl->InsertColumn(2,"Value");

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
    wxWindow::Destroy();

}


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
    for(i=0; i<(argc-1); i++)
        {
            *cont=*cont+string(argv[i])+ " ";
        }
    *cont=*cont+string(argv[argc-1]);


    /*
 for(i=0; i<argc; i++){
    *stream=+ azColName[i];
          *stream=+ " = ";
    if( argv[i] )
        *stream=+ argv[i];
    else
        *stream=+ "NULL";
     *stream=+ "\n";
 }
*/
return 0;
  //stream.flush();

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
*   Description:Get a row from db
*   Parms: void
*   Return: void
**/
string SQLManagerFrame::lb_reload(const char* tbname, const char* tcname, int id )
{

Getrow mifunc(0);
string answer;
char  num[2000];
sprintf(num,"%d",id);
LoadDll();
try
{
    mifunc=(Getrow)GetProcAddress(histDLL,"row");
    (mifunc)(db,tbname,tcname,string(num).c_str(),c_callback,&answer );
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
*   Description: Pops up a Filedialog windows and call de DLL and create a new database
*   Parms: An Event
*   Return: void
**/
void SQLManagerFrame::OnMenuNewSelected(wxCommandEvent& event)
{ wxFileDialog  SaveFileDialog(this, _("Save db file"), "", "",
                       "*.db", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    Createbase mifunc(0);
    struct stat info;
    CreateTable mifunc3(0);
    const char* tbname="datos";
    selected=-1;
    LoadDll();
    if (SaveFileDialog.ShowModal() != wxID_OK)
        return;

    const char *dbname=SaveFileDialog.GetPath().ToStdString().c_str();
    if(db!=0)
        {
            sqlite3_close(db);
        }
    if( !stat(dbname,&info)&&remove( dbname ) != 0 )
        {
    excep_dialog( "Error deleting file" );
        }
    try
  {
    mifunc=(Createbase)GetProcAddress(histDLL,"CreateDatabase");
    (mifunc)(&db,dbname);
    mifunc3=(CreateTable)GetProcAddress(histDLL,"CreateTable");
    (mifunc3)(db,tbname);

    FreeDll();
    }catch (std::exception& e)
    {
    excep_dialog(string(e.what()));
    }

    ClearAll();
    ListBox->Append("New");
    listCtrl->InsertItem(0,"New");
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
    int cont=String.find('\\')+String.find('/')+String.find(':')+String.find('*')+String.find('?')+String.find('"')+String.find('<')+String.find('>')+String.find('|');
    if(cont!=-9)
        {
         wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Can not use \\/*:?\"<>|"),
                                                             wxT("Unallowed operation"), wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
        return true;
        }
    return false;

}
/**
*   Description: Insert text in the big box.
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
*   Description: Insert text in the big box.
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
*   Description: Insert text in the big box.
*   Parms: string
*   Return: void
**/
void SQLManagerFrame::insert_text_L(string text)
{
        Libraries->Clear();
        Libraries->SetForegroundColour(wxColour(0,0,0));
        Libraries->AppendText(text);

}

/**
*   Description: clear text in the big box and listbox.
*   Parms: void
*   Return: void
**/
void SQLManagerFrame::ClearAll()
{
        BigBox->Clear();
        Libraries->Clear();
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
    wxFileDialog OpenFileDialog(this, _("Open db file"), "", "","*.db", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    selected=-1;
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
    listCtrl->InsertItem(0,"New");
    BigBoxSetStatus();

}




void SQLManagerFrame::OnListBox1Select(wxCommandEvent& event)
{
}

void SQLManagerFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
    if(selected==-1)
        return;
    ListBox->SetSelection(selected);

}

void SQLManagerFrame::BigBoxSetStatus()
{
    if(selected==-1)
    {
     Parameters->SetEditable(0);
     Libraries->SetEditable(0);
     BigBox->SetEditable(0);
     return;
    }
     Parameters->SetEditable(1);
     Libraries->SetEditable(1);
     BigBox->SetEditable(1);
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
            listCtrl->InsertItem(0,"New");
            LoadDll();
            try

            {
            additem=(add_item)GetProcAddress(histDLL,"add_item");
            (additem)(db,"datos","name",renamed.ToStdString().c_str());
            }catch (std::exception& e)
            {
            excep_dialog(string(e.what()));
            }
            try{
            getrow=(Getrow)GetProcAddress(histDLL,"id_row");
            (getrow)(db,"datos","name",renamed.ToStdString().c_str(),c_callback,&resp);
            additem=(add_item)GetProcAddress(histDLL,"add_item");
            (additem)(db,"params","id2",resp.c_str());
            resp=std::string();
            }catch (std::exception& e)
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
                (getrow)(db,"datos","ref",resp.c_str(),c_callback,&answer );
            }
            catch (std::exception& e)
            {
                excep_dialog(string(e.what()));
            }
            FreeDll();
            insert_text_L(" ");
            insert_text_P(" ");

            insert_text_BB(answer);

            BigBox->SetModified(0);
            Parameters->SetModified(0);
            Libraries->SetModified(0);
        }
    else
        {
            if(selected==sel)
                return;
            if(BigBox->IsModified()||Libraries->IsModified()||Parameters->IsModified())
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
                {
                answer=std::string();
                getrow=(Getrow)GetProcAddress(histDLL,"row");
                (getrow)(db,"datos","libs",resp.c_str(),c_callback,&answer );
                }
            catch (std::exception& e)
                {
                excep_dialog(string(e.what()));
                }
                insert_text_L(answer);
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
            Libraries->SetModified(0);
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
    //Query to delete
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
    //Query to delete
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
        (addtext)(db,"datos","ref",resp.c_str(),text.c_str());
        text=Parameters->GetLineText(0).ToStdString()==std::string()?" ":Parameters->GetLineText(0).ToStdString();
        addtext=(add_text)GetProcAddress(histDLL,"add_text");
        (addtext)(db,"datos","parms",resp.c_str(),text.c_str());
        text=Libraries->GetLineText(0).ToStdString()==std::string()?" ":Libraries->GetLineText(0).ToStdString();
        addtext=(add_text)GetProcAddress(histDLL,"add_text");
        (addtext)(db,"datos","libs",resp.c_str(),text.c_str());
        text=RadioBox->GetStringSelection().ToStdString()==std::string()?"void":RadioBox->GetStringSelection().ToStdString();
        addtext=(add_text)GetProcAddress(histDLL,"add_text");
        (addtext)(db,"datos","ret",resp.c_str(),text.c_str());

     }catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }
    FreeDll();
    BigBoxSetStatus();
    BigBox->SetModified(0);
    Libraries->SetModified(0);
    Parameters->SetModified(0);

}

void SQLManagerFrame::OnRunClick(wxCommandEvent& event)
{   string resp;
    wxString renamed;
    string code;
    string parms;
    string headfuncs;
    string libs;
    string ret;
    Getrow getrow(0);
    if(selected==-1)
        return;
    if(BigBox->IsModified()||Parameters->IsModified()||Libraries->IsModified())
        {
        wxMessageDialog *dial = new wxMessageDialog(NULL,string("Before running, you need to save it: " +ListBox->GetString(selected).ToStdString() ), wxT("Delete"), wxYES_NO);
        if(dial->ShowModal()==wxID_NO)
            return;

        OnSaveClick(event);
        }
    string text = ListBox->GetString(selected).ToStdString();
    do{
            wxTextEntryDialog  myDialog(this, _("Name of the file output"), _("New item"), _(""));
            myDialog.SetMaxLength(30);
            if ( myDialog.ShowModal() != wxID_OK )
                {
                        return;
                }
        renamed = myDialog.GetValue();
    }while(str_controler(renamed.ToStdString()));
     if (renamed.IsEmpty()||wxNOT_FOUND!=ListBox->FindString(renamed))
            {
                wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Can not leave it blank"),
                                                             wxT("Unallowed operation"), wxOK | wxICON_EXCLAMATION);
                dial->ShowModal();
                return;
            }
    LoadDll();
    try
    {
            getrow=(Getrow)GetProcAddress(histDLL,"id_row");
            (getrow)(db,"datos","name",text.c_str(),c_callback,&resp);
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","ref",resp.c_str(),c_callback,&code );
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","parms",resp.c_str(),c_callback,&parms );
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","libs",resp.c_str(),c_callback,&libs );
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","ret",resp.c_str(),c_callback,&ret );
    }
    catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }
    headfuncs=ret+" __stdcall FUNCTION_DLL "+text+"("+parms+");";
    code=" __stdcall "+ret+" "+text +"("+parms+")\n{\n"+code+"\n}";
    FreeDll();
    GenerateDllFiles_v2(renamed.ToStdString(),code,headfuncs,libs);


}
/**
void SQLManagerFrame:: GenerateDllFiles(string N_file,string action, string parms,string libs,string ret)
{   //char command[120];

    std::ofstream myfile;
    char *H_file =(char*) malloc((3*30*sizeof(char)+285*sizeof(char)));
    sprintf(H_file,"#ifndef %s_H\n#define %s_H\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n#ifdef BUILDING_DLL\n#define FUNCTION_DLL __declspec(dllexport)\n#else\n#define FUNCTION_DLL __declspec(dllimport)\n#endif\n %s __stdcall FUNCTION_DLL hello(%s);\n#ifdef __cplusplus\n}\n#endif\n#endif"
            ,N_file.c_str(),N_file.c_str(),ret.c_str(),parms.c_str());
    string cont="Dll_release\\"+N_file+".h";
    CreateDirectory(L"Dll_release",NULL);
    myfile.open (cont.c_str());
    myfile << H_file;
    myfile.close();
    free(H_file);
    char C_file[120];
    sprintf(C_file,"#include <stdio.h>\n%s\n#include \"%s.h\"\n__stdcall %s hello( %s )\n{"
            ,libs.c_str(),N_file.c_str(),ret.c_str(),parms.c_str());
    cont="Dll_release\\"+N_file+".cpp";
    myfile.open (cont.c_str());
    myfile << C_file << action << "}";
    myfile.close();
    char *command =(char*) malloc((3*30*sizeof(char)+91*sizeof(char)));

    sprintf(command,"g++ -Wall -c -DBUILDING_DLL Dll_release\\%s.cpp   & g++ -shared -o Dll_release\\%s.dll %s.o -Wl,--out-implib,Dll_release\\lib%s.a & del %s.o & pause"
            ,N_file.c_str(),N_file.c_str(),N_file.c_str(),N_file.c_str(),N_file.c_str());
    std::thread first (system,command);
    first.join();

    free(command);

}
*/

void SQLManagerFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

void SQLManagerFrame::OnPanel1Paint1(wxPaintEvent& event)
{
}

void SQLManagerFrame::LoadFile(wxCommandEvent& event)
{
}


void SQLManagerFrame::OnRun_AllClick(wxCommandEvent& event)
{
    string resp;
    wxString renamed;
    string code;
    string code_cont;
    string parms;
    string headfuncs;
    string text;
    string libs;
    string libs_cont;
    string ret;
    int n_items;
    int i;
    Getrow getrow(0);
     if(db==0)
        return;
    if(BigBox->IsModified()||Parameters->IsModified()||Libraries->IsModified())
        {
        wxMessageDialog *dial = new wxMessageDialog(NULL,string("Before running, you need to save it: " +ListBox->GetString(selected).ToStdString() ), wxT("Delete"), wxYES_NO);
        if(dial->ShowModal()==wxID_NO)
            return;
        OnSaveClick(event);
        }
    do{
            wxTextEntryDialog  myDialog(this, _("Name of the file output"), _("New item"), _(""));
            myDialog.SetMaxLength(30);
            if ( myDialog.ShowModal() != wxID_OK )
                {
                        return;
                }
        renamed = myDialog.GetValue();
    }while(str_controler(renamed.ToStdString()));
     if (renamed.IsEmpty())
            {
                wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Can not leave it blank"),
                                                             wxT("Unallowed operation"), wxOK | wxICON_EXCLAMATION);
                dial->ShowModal();
                return;
            }
    LoadDll();
    n_items=cont_col("datos");
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
                    (getrow)(db,"datos","parms",resp.c_str(),c_callback,&parms );
                    getrow=(Getrow)GetProcAddress(histDLL,"row");
                    (getrow)(db,"datos","libs",resp.c_str(),c_callback,&libs );
                    getrow=(Getrow)GetProcAddress(histDLL,"row");
                    (getrow)(db,"datos","ret",resp.c_str(),c_callback,&ret );

                    headfuncs=headfuncs+ret+" __stdcall FUNCTION_DLL "+text+"("+parms+");\n";
                    code_cont=code_cont+" __stdcall "+ret+" "+text +"("+parms+")\n{\n"+code+"\n}\n";
                    if(libs!=" ")
                        libs_cont=libs_cont+"\n"+libs;
                    resp=std::string();
                    code=std::string();
                    libs=std::string();
                    parms=std::string();
                    ret=std::string();
                }
                catch (std::exception& e)
                {
                    excep_dialog(string(e.what()));
                }

            }

        }

    FreeDll();
    GenerateDllFiles_v2(renamed.ToStdString(),code_cont,headfuncs,libs_cont);


}
void SQLManagerFrame:: GenerateDllFiles_v2(string N_file,string code, string headfuncs,string libs)
{   //char command[120];

    std::ofstream myfile;
    char *H_file =(char*) malloc((3*30*sizeof(char)+800*sizeof(char)));
    sprintf(H_file,"#ifndef __%s_H__\n#define __%s_H__\n#ifdef BUILDING_DLL\n#define FUNCTION_DLL __declspec(dllexport)\n#else\n#define FUNCTION_DLL __declspec(dllimport)\n#endif\n\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n %s\n#ifdef __cplusplus\n}\n#endif\n#endif"
            ,N_file.c_str(),N_file.c_str(),headfuncs.c_str());
    string cont="Dll_release\\"+N_file+".h";
    CreateDirectory(L"Dll_release",NULL);
    myfile.open (cont.c_str());
    myfile << H_file;
    myfile.close();
    free(H_file);
    char C_file[120];
    sprintf(C_file,"#include \"%s.h\"\n#include <stdio.h>\n%s\n "
            ,N_file.c_str(),libs.c_str());
    cont="Dll_release\\"+N_file+".cpp";
    myfile.open (cont.c_str());
    myfile << C_file << code;
//<<"\nextern \"C\" FUNCTION_DLL BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)\n{\n    switch (fdwReason)\n{\n        case DLL_PROCESS_ATTACH:\n            break;\n        case DLL_PROCESS_DETACH:\n            break;\n        case DLL_THREAD_ATTACH:\n            break;\n        case DLL_THREAD_DETACH:\n            break;\n}\nreturn TRUE; // succesful\n}";
    myfile.close();
    char *command =(char*) malloc((3*30*sizeof(char)+900*sizeof(char)));
    sprintf(command,"g++ -Wall -DBUILDING_DLL -O2  -c Dll_release\\%s.cpp -o Dll_release\\%s.o & g++ -shared -Wl,--output-def=Dll_release\\%s.def -Wl,--out-implib=Dll_release\\%s.a -Wl,--dll  Dll_release\\%s.o  -o Dll_release\\%s.dll  & pause"
            ,N_file.c_str(),N_file.c_str(),N_file.c_str(),N_file.c_str(),N_file.c_str(),N_file.c_str());
    std::thread first (system,command);
    first.join();
    free(command);
}

void SQLManagerFrame::OnLibrariesText(wxCommandEvent& event)
{
}

void SQLManagerFrame::OnRadioBox1Select(wxCommandEvent& event)
{
}

void SQLManagerFrame::OnParametersText(wxCommandEvent& event)
{
}

void SQLManagerFrame::OnListViewBeginDrag(wxListEvent& event)
{
}

void SQLManagerFrame::OnlistCtrlItemActivated(wxListEvent& event)
{
    int n=listCtrl->GetItemCount ();
    int sel=event.GetIndex();
    if(sel==-1)
        return;
    else if(n==(sel+1))
        {
    wxMessageBox("Selected index: "+wxString()<<n, "Selection Changed!",
		  wxOK);
        }
    long list_index=listCtrl->InsertItem(0,"New");
   // listCtrl->SetItem(list_index, 1, L"Text");
}
