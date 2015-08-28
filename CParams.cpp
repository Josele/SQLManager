#include "CParams.h"
#include <wx/msgdlg.h>


//(*InternalHeaders(CParams)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(CParams)
const long CParams::ID_STATICTEXT1 = wxNewId();
const long CParams::ID_STATICTEXT2 = wxNewId();
const long CParams::ID_STATICTEXT3 = wxNewId();
const long CParams::ID_TEXTCTRL1 = wxNewId();
const long CParams::ID_CHOICE1 = wxNewId();
const long CParams::ID_OK = wxNewId();
const long CParams::ID_TEXTCTRL2 = wxNewId();
const long CParams::ID_CHECKBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CParams,wxDialog)
	//(*EventTable(CParams)
	//*)
END_EVENT_TABLE()

CParams::CParams(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(CParams)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(462,126));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name"), wxPoint(16,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Type"), wxPoint(152,16), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Default value"), wxPoint(288,16), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("var"), wxPoint(16,40), wxSize(120,21), wxTE_RICH, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl1->SetMaxLength(15);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(152,40), wxSize(122,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->SetSelection( Choice1->Append(_("int")) );
	Choice1->Append(_("double"));
	Choice1->Append(_("char*"));
	Choice1->Append(_("int*"));
	Choice1->Append(_("double*"));
	Button2 = new wxButton(this, wxID_CANCEL, _("Cancel"), wxPoint(368,80), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	Button1 = new wxButton(this, ID_OK, _("Ok"), wxPoint(280,80), wxDefaultSize, 0, wxDefaultValidator, _T("ID_OK"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(288,40), wxSize(136,21), wxTE_RICH, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl2->SetMaxLength(30);
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("array"), wxPoint(16,80), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);

	Connect(ID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CParams::OnButton2Click);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&CParams::OnCheckBox1Click);
	//*)
}

CParams::~CParams()
{
	//(*Destroy(CParams)
	//*)
}


string CParams::GetName()
{
return TextCtrl1->GetLineText(0).ToStdString();
}
void CParams::SetType(string Type)
{
    unsigned int next=Type.find_first_of(" ", 0 );
    Type=Type.substr( 0, (next==string::npos?Type.length():next) );


       if (Choice1->FindString(Type)==wxNOT_FOUND)
        Choice1->SetSelection(0);
   Choice1->SetSelection(Choice1->FindString(Type));
}
void CParams::SetDefault(string Default)
{
    return TextCtrl2->SetLabel(Default);
}
void CParams::SetArray(bool status)
{
     CheckBox1->SetValue(status);

}
void CParams::SetName(string Name)
{
    TextCtrl1->SetLabel(Name);
}
string CParams::GetType()
{
    return Choice1->GetString(Choice1->GetSelection()).ToStdString();
}
bool CParams::GetArray()
{
    return CheckBox1->GetValue();
}
string CParams::GetDefault()
{
    return TextCtrl2->GetLineText(0).ToStdString();
}


void CParams::OnButton2Click(wxCommandEvent& event)
{
    std::string text=TextCtrl1->GetLineText(0).ToStdString();
     if (text==std::string()||Choice1->GetSelection()==-1)
                return;
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
        if(!(TextCtrl2->GetLineText(0).ToStdString().find_first_not_of(' ') != std::string::npos))
            TextCtrl2->Clear();
        if(!str_controler(text))
            {
                TextCtrl1->SetValue(text);
                EndModal(wxID_OK);
            }
}
void CParams::OnTextCtrl2Text(wxCommandEvent& event)
{
}
bool CParams::str_controler(string String)
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
void CParams::OnChoice1Select(wxCommandEvent& event)
{

}

void CParams::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void CParams::OnCheckBox1Click(wxCommandEvent& event)
{


}

void CParams::OnTextCtrl3Text(wxCommandEvent& event)
{
}
