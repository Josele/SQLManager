#ifndef TESTERFRAME_H
#define TESTERFRAME_H

//(*Headers(TesterFrame)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/frame.h>
//*)

class TesterFrame: public wxFrame
{
	public:

		TesterFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~TesterFrame();

		//(*Declarations(TesterFrame)
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxGrid* Grid1;
		wxStaticLine* StaticLine2;
		wxStaticLine* StaticLine1;
		wxTextCtrl* TextCtrl1;
		//*)
        void GenerateGrid(int col,int row);


	protected:

		//(*Identifiers(TesterFrame)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICLINE1;
		static const long ID_GRID1;
		static const long ID_STATICLINE2;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(TesterFrame)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
