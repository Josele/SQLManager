#ifndef __ha_H__
#define __ha_H__
#ifdef BUILDING_DLL
#define FUNCTION_DLL __declspec(dllexport)
#else
#define FUNCTION_DLL __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
 int __stdcall FUNCTION_DLL function4(double t2);
#ifdef __cplusplus
}
#endif
#endif