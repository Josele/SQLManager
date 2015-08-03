#include "ConfigDialog.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(ConfigDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ConfigDialog)
const long ConfigDialog::ID_TEXTCTRL1 = wxNewId();
const long ConfigDialog::ID_STATICTEXT1 = wxNewId();
const long ConfigDialog::ID_CHECKBOX1 = wxNewId();
const long ConfigDialog::ID_PANEL1 = wxNewId();
const long ConfigDialog::ID_NOTEBOOK1 = wxNewId();
const long ConfigDialog::ID_OK = wxNewId();
//*)

BEGIN_EVENT_TABLE(ConfigDialog,wxDialog)
	//(*EventTable(ConfigDialog)
	//*)
END_EVENT_TABLE()

ConfigDialog::ConfigDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ConfigDialog)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(234,287));
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxPoint(0,0), wxSize(232,216), 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("Text"), wxPoint(8,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Output file:"), wxPoint(8,8), wxSize(80,13), 0, _T("ID_STATICTEXT1"));
	CheckBox1 = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Tester Enable"), wxPoint(8,80), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	Notebook1->AddPage(Panel1, _("Basic"), false);
	Ok = new wxButton(this, ID_OK, _("Ok"), wxPoint(40,240), wxDefaultSize, 0, wxDefaultValidator, _T("ID_OK"));
	Cancel = new wxButton(this, wxID_CANCEL, _("Cancel"), wxPoint(136,240), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));

	Connect(ID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ConfigDialog::OnOkClick);
	//*)
}

ConfigDialog::~ConfigDialog()
{
	//(*Destroy(ConfigDialog)
	//*)
}
void ConfigDialog::SetName(string Name)
{
    TextCtrl1->SetLabel(Name);
}

string ConfigDialog::GetName()
{
return TextCtrl1->GetLineText(0).ToStdString();
}

bool ConfigDialog::str_controler(string String)
{
    int cont=String.find('@')+String.find('\'')+String.find('$')+String.find('%')+String.find('(')
                    +String.find(')')+String.find('¬')+String.find('&')+String.find('#')+String.find('~')
                        +String.find('\\')+String.find('=')+String.find('/')+String.find(':')+String.find('*')
                            +String.find('?')+String.find('"')+String.find('<')+String.find('>')+String.find('|')
                                +String.find('+')+String.find(' ')+String.find('.');
    if(cont!=-23)
        {
         wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Can not use @()#~&%$=\\/*:?\" '<.>|+"),
                                                             wxT("Unallowed operation"), wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
        return true;
        }
    return false;

}
void ConfigDialog::OnCheckListBox1Toggled(wxCommandEvent& event)
{
}

void ConfigDialog::OnOkClick(wxCommandEvent& event)
{
     std::string text=TextCtrl1->GetLineText(0).ToStdString();

    while(text.length()>0)
        {
        if(text.substr(0,1)==" ")
            {
            text=text.substr(1,text.length());
            if (text==std::string())
                return;
            }
        else
            break;
        }

        if(!str_controler(text))
            EndModal(wxID_OK);
}
