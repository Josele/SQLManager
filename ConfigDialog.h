#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

//(*Headers(ConfigDialog)
#include <wx/notebook.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
using std::string;
class ConfigDialog: public wxDialog
{
	public:

		ConfigDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ConfigDialog();

		//(*Declarations(ConfigDialog)
		wxNotebook* Notebook1;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxRadioBox* RadioBoxCC;
		wxButton* Cancel;
		wxTextCtrl* TextCtrl1;
		wxButton* Ok;
		//*)
		string GetName();
		string GetCC();
        void SetName(string Name);
        void SetCC(string sel);

	protected:

		//(*Identifiers(ConfigDialog)
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_CallC;
		static const long ID_PANEL1;
		static const long ID_NOTEBOOK1;
		static const long ID_OK;
		//*)

	private:

		//(*Handlers(ConfigDialog)
		void OnCheckListBox1Toggled(wxCommandEvent& event);
		void OnOkClick(wxCommandEvent& event);
		void OnRadioBoxCCSelect(wxCommandEvent& event);
		void OnRadioBoxCCSelect1(wxCommandEvent& event);
		//*)
        bool str_controler(string String);

		DECLARE_EVENT_TABLE()
};

#endif
