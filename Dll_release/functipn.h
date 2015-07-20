#ifndef __functipn_H__
#define __functipn_H__
#ifdef BUILDING_DLL
#define FUNCTION_DLL __declspec(dllexport)
#else
#define FUNCTION_DLL __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
 int __stdcall FUNCTION_DLL function1(int t1);
int __stdcall FUNCTION_DLL function2(int n);
int __stdcall FUNCTION_DLL funtion3(int t1);
int __stdcall FUNCTION_DLL function4( int n);

#ifdef __cplusplus
}
#endif
#endif