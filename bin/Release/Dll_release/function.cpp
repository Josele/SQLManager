#include "function.h"
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <windows.h>

 __cdecl int function1(int n)
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
