/***************************************************************
 * Name:      SQLManagerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Jose Luis Moragas ()
 * Created:   2015-06-26
 * Copyright: Jose Luis Moragas ()
 * License:
 **************************************************************/

#include "SQLManagerApp.h"

//(*AppHeaders
#include "SQLManagerMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SQLManagerApp);

bool SQLManagerApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	SQLManagerFrame* Frame = new SQLManagerFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
