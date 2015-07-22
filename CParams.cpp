#include "CParams.h"

//(*InternalHeaders(CParams)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(CParams)
const long CParams::ID_TEXTCTRL1 = wxNewId();
const long CParams::ID_OK = wxNewId();
const long CParams::ID_TEXTCTRL2 = wxNewId();
const long CParams::ID_CHOICE1 = wxNewId();
const long CParams::ID_STATICTEXT1 = wxNewId();
const long CParams::ID_STATICTEXT2 = wxNewId();
const long CParams::ID_STATICTEXT3 = wxNewId();
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
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxPoint(16,40), wxSize(120,21), wxTE_RICH, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl1->SetMaxLength(15);
	Button2 = new wxButton(this, wxID_CANCEL, _("Cancel"), wxPoint(368,80), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	Button1 = new wxButton(this, ID_OK, _("Ok"), wxPoint(272,80), wxDefaultSize, 0, wxDefaultValidator, _T("ID_OK"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxPoint(280,40), wxSize(136,21), wxTE_RICH, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl2->SetMaxLength(30);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(152,40), wxSize(104,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->Append(_("int"));
	Choice1->Append(_("double"));
	Choice1->Append(_("char*"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name"), wxPoint(16,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Type"), wxPoint(152,16), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Default value"), wxPoint(280,16), wxDefaultSize, 0, _T("ID_STATICTEXT3"));

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CParams::OnTextCtrl1Text);
	Connect(ID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CParams::OnButton2Click);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CParams::OnTextCtrl2Text);
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&CParams::OnChoice1Select);
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
string CParams::GetType()
{
return Choice1->GetString(Choice1->GetSelection()).ToStdString();
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
        EndModal(wxID_OK);
}
void CParams::OnTextCtrl2Text(wxCommandEvent& event)
{
}

void CParams::OnChoice1Select(wxCommandEvent& event)
{

}

void CParams::OnTextCtrl1Text(wxCommandEvent& event)
{
}