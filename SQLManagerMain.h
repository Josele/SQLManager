/***************************************************************
 * Name:      SQLManagerMain.h
 * Purpose:   Defines Application Frame
 * Author:    Jose Luis Moragas ()
 * Created:   2015-06-26
 * Copyright: Jose Luis Moragas ()
 * License:
 **************************************************************/

#ifndef SQLMANAGERMAIN_H
#define SQLMANAGERMAIN_H

//(*Headers(SQLManagerFrame)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/choicdlg.h>
#include <wx/statusbr.h>
//*)
#include <string.h>
#include <stdio.h>
#include "sqlite3.h"
#include <thread>
#include <list>


using std::string;
class SQLManagerFrame: public wxFrame
{
    sqlite3* db ;
    std::basic_string<TCHAR> FilePath ;
    int selected;
    public:

        SQLManagerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SQLManagerFrame();
        static  string algo;
        void callback( int argc, char **argv, char **azColName);
        static int c_callback(void* Used, int argc, char **argv, char **azColName);
        static int c_callback2(void* Used, int argc, char **argv, char **azColName);

    private:
        struct Params{
            int num;
            string cont;
            std::list<string> mytypes;

        };
        //(*Handlers(SQLManagerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnMenuNewSelected(wxCommandEvent& event);
        void OnMenuLoadSelected(wxCommandEvent& event);
        void OnListBox1Select(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnListBoxDClick(wxCommandEvent& event);
        void OnDeleteClick(wxCommandEvent& event);
        void OnSaveClick(wxCommandEvent& event);
        void OnRunClick(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnPanel1Paint1(wxPaintEvent& event);
        void LoadFile(wxCommandEvent& event);
        void OnClose1(wxCloseEvent& event);
        void OnRun_AllClick(wxCommandEvent& event);
        void OnLibrariesText(wxCommandEvent& event);
        void OnRadioBox1Select(wxCommandEvent& event);
        void OnParametersText(wxCommandEvent& event);
        void OnListViewBeginDrag(wxListEvent& event);
        void OnlistCtrlItemActivated(wxListEvent& event);
        void OnlistCtrlItemRClick(wxListEvent& event);
        void OnMenuLibrariesSelected(wxCommandEvent& event);
        void OnMenuConfigSelected(wxCommandEvent& event);
        //*)
        void OnPopupClick(wxCommandEvent &evt);
        template<class T>
        string toString(T data);
        string array_maker(string arraypar,string type);
        void FillListCtrl(string answer,string resp);
        void insert_text_BB(string text);
        void insert_text_P(string text);
        void ClearAll();
        string lb_reload(const char* tbname,const char* tcname, int id );
        int cont_col(string tbname);
        bool str_controler(string String);
        void LoadDll();
        void FreeDll();
        string get_file_contents(const char *filename);
        int existsFile(char* filename);
        void excep_dialog(string e);
        void BigBoxSetStatus();
        Params GetParams(string answer,string resp,int n);
     //   void GenerateDllFiles(string N_file,string action, string parms,string libs,string ret);
        int GenerateDllFiles_v2(string N_file,string code, string headfuncs,string libs,int N=1);

        //(*Identifiers(SQLManagerFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT3;
        static const long ID_LISTBOX;
        static const long ID_STATICLINE1;
        static const long ID_LISTCTRL;
        static const long ID_STATICTEXT5;
        static const long ID_RADIOBOX;
        static const long ID_STATICTEXT2;
        static const long ID_BigBox;
        static const long ID_deleteitem;
        static const long ID_Save;
        static const long ID_Run;
        static const long ID_Run_All;
        static const long ID_PANEL1;
        static const long ID_MenuNew;
        static const long idMenuLoad;
        static const long idMenuQuit;
        static const long ID_Config;
        static const long ID_Lib;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(SQLManagerFrame)
        wxMenuItem* MenuItem5;
        wxStaticText* StaticText2;
        wxMenu* Menu3;
        wxMenuItem* MenuItem4;
        wxButton* Run_All;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxMenuItem* MenuConfig;
        wxStaticText* StaticText3;
        wxRadioBox* RadioBox;
        wxButton* Save;
        wxButton* Delete;
        wxMenuItem* MenuItem3;
        wxStaticText* StaticText5;
        wxStatusBar* StatusBar1;
        wxTextCtrl* BigBox;
        wxStaticLine* StaticLine1;
        wxListCtrl* listCtrl;
        wxButton* Run;
        wxMultiChoiceDialog* MultiChoiceDialog1;
        wxListBox* ListBox;
        //*)
        bool retstatus;
        std::thread first;
        wxString MultiChoiceDialogChoices_1[13];
        DECLARE_EVENT_TABLE()
};

#endif // SQLMANAGERMAIN_H
