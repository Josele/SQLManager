#ifndef __h_H__
#define __h_H__
#ifdef BUILDING_DLL
#define FUNCTION_DLL __declspec(dllexport)
#else
#define FUNCTION_DLL __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
 void __stdcall FUNCTION_DLL na( );
#ifdef __cplusplus
}
#endif
#endif