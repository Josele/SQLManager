#include "function.h"
#include <stdio.h>
#include <math.h>
#include <windows.h>

   FUNCTION_DLL int function1(int* var,double* var_double,char* foo_string,char* container [],int size)
{
int result;
int i=0;
*var=*var*2;
*var_double=sqrt(4.2);
Sleep(*var);
for(i;i<size;i++)
{
	if(container[i]==foo_string)
		break;
}
result=i;
return result;
}
  FUNCTION_DLL void function2(int n)
{
  for (int i=2; i<=n; ++i)
        for (int j=sqrt(i);j>1;--j)
            if (i%j==0)
            {
                break;
            }

 
}
