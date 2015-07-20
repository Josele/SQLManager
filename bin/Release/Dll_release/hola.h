#ifndef hola_H
#define hola_H
#ifdef __cplusplus
extern "C" {
#endif
#ifdef BUILDING_DLL
#define FUNCTION_DLL __declspec(dllexport)
#else
#define FUNCTION_DLL __declspec(dllimport)
#endif
 int __stdcall FUNCTION_DLL hello( int in );
#ifdef __cplusplus
}
#endif
#endif