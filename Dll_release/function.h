#ifndef __function_H__
#define __function_H__
#ifdef BUILDING_DLL
#define FUNCTION_DLL __declspec(dllexport)
#else
#define FUNCTION_DLL __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
 void __cdecl FUNCTION_DLL function2(int size);
int __cdecl FUNCTION_DLL function1(int n);

#ifdef __cplusplus
}
#endif
#endif