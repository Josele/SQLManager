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


//(*InternalHeaders(SQLManagerFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)
HINSTANCE histDLL;
//helper functions
//try to work with an array
typedef int (*Createbase) (sqlite3**,const char*);
typedef int (*Callblback)(void*,int,char**,char**);
typedef int (*CreateTable) (sqlite3*,const char*,char*  );
typedef int (*add_item) (sqlite3* db, string ,string ,string );
typedef int (*add_text) (sqlite3* db, string ,string ,string,string );
typedef int (*del_item) (sqlite3* db, string  ,string );
typedef int (*Getrow) (sqlite3* , string ,string,string,int (*callback)(void*,int,char**,char**),void* );
typedef int (*Nrow) (sqlite3* , string,int (*callback)(void*,int,char**,char**),void*  );


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
const long SQLManagerFrame::ID_RADIOBOX1 = wxNewId();
const long SQLManagerFrame::ID_TEXTCTRL1 = wxNewId();
const long SQLManagerFrame::ID_BigBox = wxNewId();
const long SQLManagerFrame::ID_deleteitem = wxNewId();
const long SQLManagerFrame::ID_BUTTON1 = wxNewId();
const long SQLManagerFrame::ID_Save = wxNewId();
const long SQLManagerFrame::ID_Run = wxNewId();
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

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
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
    FlexGridSizer2->AddGrowableRow(0);
    FlexGridSizer2->AddGrowableRow(1);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Params"), wxDefaultPosition, wxSize(114,15), 0, _T("ID_STATICTEXT4"));
    FlexGridSizer2->Add(StaticText4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Return"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer2->Add(StaticText5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Extra Libraries"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer2->Add(StaticText3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Parameters = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(114,28), wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_RICH2, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer2->Add(Parameters, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxString __wxRadioBoxChoices_1[3] =
    {
    	_("void"),
    	_("int"),
    	_("char*")
    };
    RadioBox = new wxRadioBox(Panel1, ID_RADIOBOX1, wxEmptyString, wxDefaultPosition, wxSize(183,36), 3, __wxRadioBoxChoices_1, 1, wxRA_VERTICAL|wxNO_BORDER, wxDefaultValidator, _T("ID_RADIOBOX1"));
    FlexGridSizer2->Add(RadioBox, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    Libraries = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(60,19)), wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_RICH2, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    Libraries->SetMaxSize(wxSize(-1,-1));
    FlexGridSizer2->Add(Libraries, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(FlexGridSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BigBox = new wxTextCtrl(Panel1, ID_BigBox, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(532,228)), wxTE_AUTO_SCROLL|wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_MULTILINE|wxTE_RICH2|wxVSCROLL, wxDefaultValidator, _T("ID_BigBox"));
    BigBox->SetMinSize(wxSize(400,-1));
    BoxSizer3->Add(BigBox, 6, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_TOP, 6);
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
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SQLManagerFrame::OnTextCtrl2Text);
    Connect(ID_BigBox,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SQLManagerFrame::OnTextCtrl1Text);
    Connect(ID_deleteitem,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::OnDeleteClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::LoadFile);
    Connect(ID_Save,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::OnSaveClick);
    Connect(ID_Run,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SQLManagerFrame::OnRunClick);
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


// Parameters are:
//      argc -- the number of rows in the resultset
//      argv[] -- the data for each row
//      azColName -- the name of each column
   int SQLManagerFrame::c_callback(void* Used, int argc, char **argv, char **azColName){
    int i;
    string* cont = static_cast<string*>(Used);
    for(i=0; i<argc; i++){
    *cont=*cont + string(argv[i])+ " ";
    }


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
string SQLManagerFrame::lb_reload(string tbname, string tcname, int id )
{

Getrow mifunc(0);
string answer;
string result;
char  num[2000];
itoa(id,num,10);
LoadDll();
try
{
    mifunc=(Getrow)GetProcAddress(histDLL,"row");
    result=(mifunc)(db,tbname,tcname,string(num),c_callback,&answer );
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
    result=(mifunc5)(db,tbname,c_callback,&answer );
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
    char* db_err=0;
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
    (mifunc3)(db,tbname,db_err);

    FreeDll();
    }catch (std::exception& e)
    {
    excep_dialog(string(e.what()));
    }

    ClearAll();
    ListBox->Append("New");
    BigBoxSetStatus();

}


/**
*   Description: Pops up a dialog windows showing an exception or error
*   Parms: string
*   Return: void
**/
void SQLManagerFrame::excep_dialog(string e)
{
    wxMessageDialog *dial = new wxMessageDialog(NULL,e, wxT("Exception"), wxOK);
    dial->ShowModal();

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
        insert_text_BB((" Sqlite3 code error :"));
        return;
        }
    ClearAll();
    result=cont_col("datos");
    for(i=0;i<result;i++)
        {
            str=lb_reload("datos","name",i);
            if (str.Len() > 0)
            ListBox->Append(str.substr(0,str.length()-1));
        }
    ListBox->Append("New");
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
    int sel = ListBox->GetSelection();
    if (sel == -1)
        {
        return;
        }
    else if(ListBox->GetCount()==(sel+1))
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
        }while(renamed.IsSameAs("new")||renamed.IsSameAs("New")||renamed.IsSameAs("NEW"));

        if (renamed.IsEmpty())
            {
                return;
            }
            ListBox->Delete(sel);
            ListBox->Insert(renamed, sel);
            ListBox->Append("New");
            LoadDll();
            try
            {
            additem=(add_item)GetProcAddress(histDLL,"add_item");
            (additem)(db,"datos","name",renamed.ToStdString());
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
            (getrow)(db,"datos","name",text.ToStdString(),c_callback,&resp);
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","ref",resp,c_callback,&answer );
            }
            catch (std::exception& e)
            {
            excep_dialog(string(e.what()));
            }
            FreeDll();
            insert_text_BB(answer.substr(0,answer.length()-1));
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
            wxMessageDialog *dial = new wxMessageDialog(NULL,string("The file has been modify, do you want to save your changes: " +ListBox->GetString(selected).ToStdString() ), wxT("Save"), wxYES_NO);
            if(dial->ShowModal()==wxID_YES){
                OnSaveClick(event);
                }

            }
            //char n[2];
            //insert_text_BB(string(itoa(sel,n,10)));
            text = ListBox->GetString(sel);
            LoadDll();
            try
            {
            getrow=(Getrow)GetProcAddress(histDLL,"id_row");
            (getrow)(db,"datos","name",text.ToStdString(),c_callback,&resp);
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","ref",resp,c_callback,&answer );
            }
            catch (std::exception& e)
            {
            excep_dialog(string(e.what()));
            }
            FreeDll();
            selected=sel;
            insert_text_BB(answer.substr(0,answer.length()-1));

            LoadDll();
            try
            {
            answer=std::string();
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","parms",resp,c_callback,&answer );
            }
            catch (std::exception& e)
            {
            excep_dialog(string(e.what()));
            }
            FreeDll();

            insert_text_P(answer.substr(0,answer.length()-1));    LoadDll();
            try
            {
            answer=std::string();
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","libs",resp,c_callback,&answer );
            }
            catch (std::exception& e)
            {
            excep_dialog(string(e.what()));
            }
            FreeDll();
            insert_text_L(answer.substr(0,answer.length()-1));
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
    del_item delitem(0);
    char  num[2000];
    if(selected==-1)
        {
        return;
        }

    text = ListBox->GetString(selected);
    wxMessageDialog *dial = new wxMessageDialog(NULL,string("Are you sure you want to delete: " +text ), wxT("Delete"), wxYES_NO);
    if(dial->ShowModal()==wxID_NO)
        return;
    //Query to delete
    itoa(selected,num,10);
    LoadDll();
    try
    {
        getid=(Getrow)GetProcAddress(histDLL,"id_row");
        (getid)(db,"datos","name",text.ToStdString(),c_callback,&resp);
        delitem=(del_item)GetProcAddress(histDLL,"del_item");
        (delitem)(db,"datos",resp);
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
    char  num[2000];
    if(selected==-1)
        return;
    string name=ListBox->GetString(selected).ToStdString();
    if(event.GetId()==ID_Save)
    {
    wxMessageDialog *dial = new wxMessageDialog(NULL,string("Are you sure you want to overwrite: " +name ), wxT("Save"), wxYES_NO);
    if(dial->ShowModal()==wxNO)
        return;

    }
    //Query to delete
    itoa(selected,num,10);
    text="";
    int n_lines=BigBox->GetNumberOfLines();
    for(i=0;i<n_lines;i++)
        text=text+BigBox->GetLineText(i).ToStdString()+"\n";
    LoadDll();
    try
    {
        getid=(Getrow)GetProcAddress(histDLL,"id_row");
        (getid)(db,"datos","name",name,c_callback,&resp);
        addtext=(add_text)GetProcAddress(histDLL,"add_text");
        (addtext)(db,"datos","ref",resp,text);
        text=Parameters->GetLineText(0).ToStdString()==std::string()?" ":Parameters->GetLineText(0).ToStdString();
        addtext=(add_text)GetProcAddress(histDLL,"add_text");
        (addtext)(db,"datos","parms",resp,text);
        text=Libraries->GetLineText(0).ToStdString()==std::string()?" ":Libraries->GetLineText(0).ToStdString();
        addtext=(add_text)GetProcAddress(histDLL,"add_text");
        (addtext)(db,"datos","libs",resp,text);

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
{
    string resp;
    string code;
    string parms;
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
        }
    OnSaveClick(event);
    string text = ListBox->GetString(selected).ToStdString();
    LoadDll();
    try
    {
            getrow=(Getrow)GetProcAddress(histDLL,"id_row");
            (getrow)(db,"datos","name",text,c_callback,&resp);
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","ref",resp,c_callback,&code );
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","parms",resp,c_callback,&parms );
            getrow=(Getrow)GetProcAddress(histDLL,"row");
            (getrow)(db,"datos","libs",resp,c_callback,&libs );
    }
    catch (std::exception& e)
    {
        excep_dialog(string(e.what()));
    }
    FreeDll();
    ret=RadioBox->GetString(RadioBox->GetSelection()).ToStdString();
    GenerateDllFiles(text,code,parms,libs,ret);


}

void SQLManagerFrame:: GenerateDllFiles(string N_file,string action, string parms,string libs,string ret)
{   //char command[120];

    std::ofstream myfile;
    char *H_file =(char*) malloc((3*30*sizeof(char)+285*sizeof(char)));
    sprintf(H_file,"#ifndef %s_H\n#define %s_H\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n#ifdef BUILDING_DLL\n#define FUNCTION_DLL __declspec(dllexport)\n#else\n#define FUNCTION_DLL __declspec(dllimport)\n#endif\n %s __stdcall FUNCTION_DLL hello(%s);\n#ifdef __cplusplus\n}\n#endif\n#endif"
            ,N_file.c_str(),N_file.c_str(),ret.c_str(),parms.c_str());
    string cont=N_file+".h";
    myfile.open (cont.c_str());
    myfile << H_file;
    myfile.close();
    free(H_file);
    char C_file[800];
    sprintf(C_file,"#include <stdio.h>\n%s\n#include \"%s.h\"\n__stdcall %s hello( %s )\n{"
            ,libs.c_str(),N_file.c_str(),ret.c_str(),parms.c_str());
    cont=N_file+".cpp";
    myfile.open (cont.c_str());
    myfile << C_file << action << "}";
    myfile.close();
    char *command =(char*) malloc((3*30*sizeof(char)+91*sizeof(char)));

    sprintf(command,"g++ -Wall -c -DBUILDING_DLL %s.cpp & pause & g++ -shared -o %s.dll %s.o -Wl,--out-implib,lib%s.a & pause"
            ,N_file.c_str(),N_file.c_str(),N_file.c_str(),N_file.c_str());
    system(command);
    free(command);


}

void SQLManagerFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

void SQLManagerFrame::OnPanel1Paint1(wxPaintEvent& event)
{
}

void SQLManagerFrame::LoadFile(wxCommandEvent& event)
{
}

void SQLManagerFrame::OnTextCtrl2Text(wxCommandEvent& event)
{
}
