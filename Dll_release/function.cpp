#include "function.h"
#include <stdio.h>

#include <windows.h>
  __stdcall int function1( )
{
return 100; 



}
 __stdcall void function2( )
{
system("pause");
}
 __stdcall int function3(int t2,int t1)
{
return t2/t1;
}
 __stdcall int function4(double t2)
{
return t2*8;
}
 __stdcall int function5( )
{
return 8%5;
}
 __stdcall void fucntion7( )
{

int m=0;
m=3*8;
}
 __stdcall int hola( )
{
return 8;
}
