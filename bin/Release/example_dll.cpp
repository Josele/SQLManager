#include <stdio.h>
#include <windows.h>
#include "example_dll.h"
__stdcall void hello(const char *s)
{printf("Hello %s\n", s);
system("pause");












 }