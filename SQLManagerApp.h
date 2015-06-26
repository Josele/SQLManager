/***************************************************************
 * Name:      SQLManagerApp.h
 * Purpose:   Defines Application Class
 * Author:    Jose Luis Moragas ()
 * Created:   2015-06-26
 * Copyright: Jose Luis Moragas ()
 * License:
 **************************************************************/

#ifndef SQLMANAGERAPP_H
#define SQLMANAGERAPP_H

#include <wx/app.h>

class SQLManagerApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // SQLMANAGERAPP_H
