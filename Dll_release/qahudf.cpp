#include "qahudf.h"
#include <stdio.h>

 #include <windows.h>
  __stdcall int function1(int t1)
{
return t1*2;
}
 __stdcall int function2(int n)
{
return 256;
}
 __stdcall int funtion3(int t1)
{
int p=t1*t1;
return p;
}
 __stdcall int function4( int n)
{
int i;
for(i=1;i<10;i++)
n=n*i;
return n;
}
