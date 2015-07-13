#ifndef example_dll_H
#define example_dll_H
#ifdef __cplusplus
extern "C" {
#endif
#ifdef BUILDING_DLL
#define FUNCTION_DLL __declspec(dllexport)
#else
#define FUNCTION_DLL __declspec(dllimport)
#endif
void __stdcall FUNCTION_DLL hello(const char *s);
#ifdef __cplusplus
}
#endif
#endif