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
 int __stdcall FUNCTION_DLL function1( );
void __stdcall FUNCTION_DLL function2( );
int __stdcall FUNCTION_DLL function3(int t2,int t1);
int __stdcall FUNCTION_DLL function4(double t2);
int __stdcall FUNCTION_DLL function5( );
void __stdcall FUNCTION_DLL fucntion7( );
int __stdcall FUNCTION_DLL hola( );

#ifdef __cplusplus
}
#endif
#endif