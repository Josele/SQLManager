#ifndef __ada_H__
#define __ada_H__
#ifdef BUILDING_DLL
#define FUNCTION_DLL __declspec(dllexport)
#else
#define FUNCTION_DLL __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
 int __stdcall FUNCTION_DLL function2(int n);
#ifdef __cplusplus
}
#endif
#endif