#ifndef TESTERDIALOG_H
#define TESTERDIALOG_H

//(*Headers(TesterDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/splitter.h>
#include <wx/statline.h>
#include <wx/grid.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include <list>

using std::string;
struct FuncDescr
        {
            int num;
            string name;
            string ret;
            std::list<string> mytypes;
        };
class TesterDialog: public wxDialog
{
	public:

		TesterDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~TesterDialog();
		//(*Declarations(TesterDialog)
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxGrid* Grid1;
		wxStaticLine* StaticLine2;
		wxStaticLine* StaticLine1;
		wxTextCtrl* TextCtrl1;
		wxSplitterWindow* SplitterWindow1;
		wxButton* Launch;
		//*)
        void GenerateGrid(int col,int row);
        void RowName(string name,int row);
        void FileName(string file);
        void ColorSet(FuncDescr descriptor,int row);
        void AddReturn();


	protected:

		//(*Identifiers(TesterDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICLINE1;
		static const long ID_GRID1;
		static const long ID_SPLITTERWINDOW1;
		static const long ID_STATICLINE2;
		static const long ID_Launch;
		//*)

	private:
     struct Result{

            std::list<string> Time;
            std::list<string> Value;

        };
		//(*Handlers(TesterDialog)
		void OnLaunchClick(wxCommandEvent& event);
		//*)
		template<class T>
        string toString(T data);
        string funcpointer();
        string funcretdecl();
        string funccallers();
        string funcdecl();

        unsigned long m_value=5;
        wxArrayString excludeString;
        std::list<FuncDescr> ListOfList;
        std::list<Result> AllResult;
        int row,col;
        string file;

		DECLARE_EVENT_TABLE()

};

#endif
