#include "function.h"
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

  __cdecl FUNCTION_DLL void function2(int size,int var[])
{
for(int n=0;n<size;n++)
{
	var[n]=rand() % 100;
	var[n]=pow(var[n],2);
}

 
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
