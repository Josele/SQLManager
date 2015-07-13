#ifndef na_H
#define na_H
#ifdef __cplusplus
extern "C" {
#endif
#ifdef BUILDING_DLL
#define FUNCTION_DLL __declspec(dllexport)
#else
#define FUNCTION_DLL __declspec(dllimport)
#endif
 int __stdcall FUNCTION_DLL hello(int n, int n2 );
#ifdef __cplusplus
}
#endif
#endif