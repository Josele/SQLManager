#include "function.h"
#include <stdio.h>
#include <math.h>

  __stdcall int function1(int n)
{
int result;

    result=n-1;

    for (int i=2; i<=n; ++i)
        for (int j=sqrt(i);j>1;--j)
            if (i%j==0)
            {
                --result;
                break;
            }


return result;
}

extern "C" FUNCTION_DLL BOOLEAN APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
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