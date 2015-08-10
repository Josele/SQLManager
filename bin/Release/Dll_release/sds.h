#ifndef __sds_H__
#define __sds_H__
#ifdef BUILDING_DLL
#define FUNCTION_DLL __declspec(dllexport)
#else
#define FUNCTION_DLL __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
 int __stdcall FUNCTION_DLL na(int var,int vars);
void __stdcall FUNCTION_DLL _( );
void __stdcall FUNCTION_DLL ¿(int var,int vara=a,int vars);

#ifdef __cplusplus
}
#endif
#endif