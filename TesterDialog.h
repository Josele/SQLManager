#ifndef TESTERDIALOG_H
#define TESTERDIALOG_H

//(*Headers(TesterDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/grid.h>
#include <wx/dialog.h>
//*)

class TesterDialog: public wxDialog
{
	public:

		TesterDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~TesterDialog();

		//(*Declarations(TesterDialog)
		wxStaticText* StaticText1;
		wxGrid* Grid1;
		wxStaticLine* StaticLine2;
		wxStaticLine* StaticLine1;
		wxTextCtrl* TextCtrl1;
		//*)
        void GenerateGrid(int col,int row);


	protected:

		//(*Identifiers(TesterDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICLINE1;
		static const long ID_GRID1;
		static const long ID_STATICLINE2;
		//*)

	private:

		//(*Handlers(TesterDialog)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
