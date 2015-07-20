#include "funtion.h"
#include <stdio.h>
#include <windows.h>
  __stdcall void function2( )
{
system("pause");
}
extern "C" FUNCTION_DLL BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
{
        case DLL_PROCESS_ATTACH:
            break;
        case DLL_PROCESS_DETACH:
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:
            break;
}
return TRUE; // succesful
}