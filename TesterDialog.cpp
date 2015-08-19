#include "TesterDialog.h"

//(*InternalHeaders(TesterDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/valnum.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <wx/progdlg.h>
#include <wx/msgdlg.h>

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

 	excludeString.Add(",,");

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

string TesterDialog::funcpointer()
{   std::list<FuncDescr> lol=ListOfList;
    string funchp;
    while(!lol.empty())
    {
        funchp=funchp+" typedef "+lol.front().ret+"(*"+lol.front().name+") ( ";
        while(!lol.front().mytypes.empty())
        {
            funchp=funchp+" "+lol.front().mytypes.front()+",";
            lol.front().mytypes.pop_front();
        }
        funchp=funchp.substr(0,funchp.length()-1)+");\n";
        lol.pop_front();
    }
return funchp;
}

string TesterDialog::funcdecl()
{
    std::list<FuncDescr> lol=ListOfList;
    string funchp;
    while(!lol.empty())
    {
        funchp=funchp +lol.front().name+" call_"+lol.front().name+"(0);\n";
        lol.pop_front();
    }
return funchp;
}
string TesterDialog::funccallers()
{
    int row=0;
    int col=0;
    std::list<FuncDescr> lol=ListOfList;
    const char* countingst="       begin = high_resolution_clock::now();\n" ;
    const char* countingen="       end = high_resolution_clock::now();\n";
    const char* countingen2="       ticks = duration_cast<microseconds>(end-begin);\n      myfile<<ticks.count()<<\"\\n\";\n\n" ;
    string funchp;
    while(!lol.empty())
    {
        funchp=funchp+countingst+"      call_"+lol.front().name+"=("+lol.front().name+")GetProcAddress(histDLL,\""+lol.front().name+"\");\n";
        funchp=funchp+(lol.front().ret=="void"?"      myfile<< \"void,,\";\n":"      myfile<<")+"(call_"+lol.front().name+")( ";

        while(!lol.front().mytypes.empty())
        {
            funchp=funchp+(lol.front().mytypes.front()=="char*"?"\""+Grid1->GetCellValue(row,col)+"\"":Grid1->GetCellValue(row,col))+",";
            lol.front().mytypes.pop_front();
            col++;
        }
        funchp=funchp.substr(0,funchp.length()-1)+")"+(lol.front().ret!="void"?"<<\",,\"":"")+";\n"+countingen+(row==0?"auto":"")+countingen2;
        lol.pop_front();
        row++;
        col=0;
    }
return funchp;
}
void TesterDialog::FileName(string file)
{
 this->file=file;
}
string TesterDialog::funcretdecl()
{
    std::list<FuncDescr> lol=ListOfList;
    string funchp;
    while(!lol.empty())
    {   if(lol.front().ret!="void")
            funchp=funchp +lol.front().ret+" result_"+lol.front().name+";\n";
        lol.pop_front();
    }
return funchp;
}

void TesterDialog::GenerateGrid(int col,int row)
{
    int n;
    this->row=row;
    this->col=col;

    Grid1->CreateGrid(row,col+2);
    for(n=0;n<col;n++)
        Grid1->SetColLabelValue(n,"P"+toString(n));
    Grid1->SetColLabelValue(n,"Return");
    Grid1->SetColLabelValue(n+1,"Time");
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
void TesterDialog::ColorSet(FuncDescr descriptor,int row )
{
    ListOfList.push_back(descriptor);
    string temp;
    int n=0;
    while( !descriptor.mytypes.empty() )
    {
        //Grid1->SetReadOnly(row,n,false);
        temp=descriptor.mytypes.front();

            if("int"==temp)
                Grid1->SetCellBackgroundColour(row,n,wxColour(255,0,0));
            else if("double"==temp)
                Grid1->SetCellBackgroundColour(row,n,wxColour(0,0,255));

            else if("char*"==temp)
                Grid1->SetCellBackgroundColour(row,n,wxColour(0,255,0));



        n++;
        descriptor.mytypes.pop_front();
    }

    }


void TesterDialog::OnLaunchClick(wxCommandEvent& event)
{
    int offset=0;
    int i=0;
    int j=0;
    int addcol=atoi(TextCtrl1->GetLineText(0).ToStdString().c_str());
    string line;
    boolean skip=false;
    string container;
    string delimiters = ",";
    size_t current;
    size_t cuter;
    size_t next = -1;
    const char* cont="Dll_release\\tester.cpp";
    const char* funcoutstream="const char* cont=\"output.txt\";\nstd::ofstream myfile;\nmyfile.open(cont);\n";
    const char* autodecl="auto  begin = high_resolution_clock::now();\nauto end = high_resolution_clock::now();\nauto   ticks = duration_cast<microseconds>(end-begin);\n";
    char* open_dll=(char*) malloc(120*sizeof(char));
    sprintf(open_dll,"histDLL= LoadLibrary(\"%s.dll\");\n    if (histDLL != NULL){\n",file.c_str());
    std::ofstream myfile;
    const char* C_file="#include <iostream>\n#include <windows.h>\n#include <fstream>\n#include <stdio.h>\n#include <chrono>\nusing namespace std;\nusing namespace std::chrono;\nHINSTANCE histDLL;\n";
    myfile.open (cont);
    myfile << C_file<< funcpointer()<<"int main(int argc,char **argv)\n{\n"<<funcdecl()<<funcoutstream<<autodecl<<open_dll<<funccallers()<<"      FreeLibrary(histDLL);\n      }\nreturn 0;\n}";


    myfile.close();
    int n=system(" (g++ -std=c++11 -O2 -c -o  Dll_release\\tester.o  Dll_release\\tester.cpp ||(exit 1) )& g++ -o Dll_release\\tester.exe Dll_release\\tester.o ||(exit 1)");
    if(n!=0)
        {
        wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Check if all parameters are fill"),
                         wxT("Compilation Fail"), wxOK | wxICON_ERROR);
        dial->ShowModal();
        return;
        }
    system("Dll_release\\tester.exe");

    std::ifstream infile;
    if(Grid1->GetNumberCols()>(col+2))
        Grid1->DeleteCols(col+2,(Grid1->GetNumberCols()-2));

     if(addcol>2)
        Grid1->AppendCols(addcol-1);
    for(n=(col+1);n<((col+1)+addcol);n++)
        Grid1->SetColLabelValue(n,"Time");

    do{

        infile.open("output.txt");
         if (infile.is_open())
        {
            while ( infile.good() )
                {
                    getline (infile,line);
                    if(line=="")
                        break;
                    cuter= next + 1;
                    do{
                        current = next + 1;
                        next = line.find_first_of(delimiters, current );
                            if(next == string::npos||(line.substr(next,2)==",,"))
                            {

                                container=line.substr( cuter, next - cuter );
                                if(!(skip&&((j)==0)))
                                    Grid1->SetCellValue(i,col+j+offset,container);
                                j++;
                                next=(next==-1)?-1:next++;
                                cuter=next+2;
                            }
                            //skip=false;
                         }while (next != string::npos);
                     next=-1;
                     j=0;
                    // j=offset;
                     i++;


                }
                 skip=true;
            infile.close();

        offset++;
        addcol--;
        i=0;
        system("Dll_release\\tester.exe");

        }

        }while((addcol)>0);


   // wxGridTableBase* portablas=Grid1->GetTable();
   remove("Dll_release\\tester.exe");
   // remove("Dll_release\\tester.cpp");

    /** int n=0;



   wxProgressDialog progressDlg(_("Please wait"), _("Scanning"),1000, this, wxPD_APP_MODAL | wxPD_CAN_ABORT);
    for(n;n<1000;n++)
        {
        if (!progressDlg.Update(n)) // if cancel clicked
            return; // abort processing

        Sleep(10);

        }*/
}
