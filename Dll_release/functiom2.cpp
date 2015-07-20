#include "functiom2.h"
#include <stdio.h>
 
  __stdcall int function4(double t2)
{
return t2*8;
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