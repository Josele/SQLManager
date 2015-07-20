#ifndef __sdasda_H__
#define __sdasda_H__
#ifdef BUILDING_DLL
#define FUNCTION_DLL __declspec(dllexport)
#else
#define FUNCTION_DLL __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
 int __stdcall FUNCTION_DLL funtion3(int t1);
#ifdef __cplusplus
}
#endif
#endif