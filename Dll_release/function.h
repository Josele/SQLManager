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
 int  FUNCTION_DLL function1(int* var,double* var_double,char* foo_string,char* container [],int size);
void  FUNCTION_DLL function2(int n);

#ifdef __cplusplus
}
#endif
#endif