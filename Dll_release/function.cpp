#include "function.h"
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <windows.h>

  __cdecl FUNCTION_DLL char* function2(int size)
{
char* result;
result="My house";
Sleep(size);

return result;
}
 __cdecl FUNCTION_DLL int function1(int n)
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
 __cdecl FUNCTION_DLL void jaja(int* var2,int* varsdvs,double* varsdaa)
{
*var2=*var2*2;
*varsdaa=*varsdaa*2;
Sleep(*var2);
 
}
