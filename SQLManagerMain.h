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
#include <wx/menu.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)
#include <string.h>
#include "sqlite3.h"

class SQLManagerFrame: public wxFrame
{
    sqlite3* db ;
    std::basic_string<TCHAR> FilePath ;
    public:

        SQLManagerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SQLManagerFrame();

    private:

        //(*Handlers(SQLManagerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnMenuNewSelected(wxCommandEvent& event);
        void OnClose1(wxCloseEvent& event);
        void OnMenuLoadSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(SQLManagerFrame)
        static const long ID_MENUITEM1;
        static const long idMenuQuit;
        static const long idMenuLoad;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(SQLManagerFrame)
        wxMenuItem* MenuItem4;
        wxFileDialog* FileDialog1;
        wxMenuItem* MenuItem3;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SQLMANAGERMAIN_H
