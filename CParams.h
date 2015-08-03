#ifndef CPARAMS_H
#define CPARAMS_H

//(*Headers(CParams)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
using std::string;

class CParams: public wxDialog
{
	public:

		CParams(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~CParams();
        string GetName();
        string GetType();
        string GetDefault();
        bool GetArray();
        void SetArray(bool status);
        void SetName(string Name);
        void SetType(string Type);
        void SetDefault(string Default);
		//(*Declarations(CParams)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxCheckBox* CheckBox1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl3;
		wxChoice* Choice1;
		//*)

	protected:

		//(*Identifiers(CParams)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_CHOICE1;
		static const long ID_TEXTCTRL2;
		static const long ID_OK;
		static const long ID_CHECKBOX1;
		static const long ID_TEXTCTRL3;
		//*)

	private:
		//(*Handlers(CParams)
		void OnButton2Click(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnChoice1Select(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnCheckBox1Click(wxCommandEvent& event);
		void OnTextCtrl3Text(wxCommandEvent& event);
		//*)
    bool str_controler(string String);

		DECLARE_EVENT_TABLE()
};

#endif
