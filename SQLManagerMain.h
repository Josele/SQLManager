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
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)
#include <string.h>
#include <stdio.h>
#include "sqlite3.h"

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

    private:

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
        //*)
        void insert_text(string text);
        void ClearAll();
        string lb_reload(string tbname,string tcname, int id );
        int cont_col(string tbname);
        void LoadDll();
        void FreeDll();
        void excep_dialog(string e);
        void BigBoxSetStatus();
        void GenerateDllFiles(string N_file,string action);
        //(*Identifiers(SQLManagerFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_LISTBOX;
        static const long ID_STATICLINE1;
        static const long ID_BigBox;
        static const long ID_deleteitem;
        static const long ID_BUTTON1;
        static const long ID_Save;
        static const long ID_Run;
        static const long ID_PANEL1;
        static const long ID_MenuNew;
        static const long idMenuLoad;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)
        string stream;
        //(*Declarations(SQLManagerFrame)
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxMenuItem* MenuItem4;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxButton* Save;
        wxButton* Delete;
        wxMenuItem* MenuItem3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* BigBox;
        wxStaticLine* StaticLine1;
        wxButton* Run;
        wxListBox* ListBox;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SQLMANAGERMAIN_H
