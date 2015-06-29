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
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/button.h>
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
        void OnMenuLoadSelected(wxCommandEvent& event);
        void OnListBox1Select(wxCommandEvent& event);
        //*)

        //(*Identifiers(SQLManagerFrame)
        static const long ID_LISTBOX1;
        static const long ID_STATICLINE1;
        static const long ID_TEXTCTRL1;
        static const long ID_deleteitem;
        static const long ID_Save;
        static const long ID_Run;
        static const long ID_MenuNew;
        static const long idMenuLoad;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(SQLManagerFrame)
        wxMenuItem* MenuItem4;
        wxButton* Save;
        wxButton* Delete;
        wxMenuItem* MenuItem3;
        wxStatusBar* StatusBar1;
        wxStaticLine* StaticLine1;
        wxTextCtrl* TextCtrl1;
        wxButton* Run;
        wxListBox* ListBox1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SQLMANAGERMAIN_H
