#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
HINSTANCE histDLL;
 typedef char*(*function2) (  int);
 typedef int(*function1) (  int);
 typedef void(*jaja) (  int*, int*, double*);
int main(int argc,char **argv)
{
function2 call_function2(0);
function1 call_function1(0);
jaja call_jaja(0);
const char* cont="output.txt";
std::ofstream myfile;
myfile.open(cont);
auto  begin = high_resolution_clock::now();
auto end = high_resolution_clock::now();
auto   ticks = duration_cast<microseconds>(end-begin);
histDLL= LoadLibrary("function.dll");
    if (histDLL != NULL){
double cont24;
cont24=123;
int cont14;
cont14=123;
int cont04;
cont04=123;
       begin = high_resolution_clock::now();
      call_function2=(function2)GetProcAddress(histDLL,"function2");
      myfile<<(call_function2)( 12)<<",,";
       end = high_resolution_clock::now();
auto       ticks = duration_cast<microseconds>(end-begin);
      myfile<<ticks.count()<<"";
      myfile<<"\n";

       begin = high_resolution_clock::now();
      call_function1=(function1)GetProcAddress(histDLL,"function1");
      myfile<<(call_function1)( 123)<<",,";
       end = high_resolution_clock::now();
       ticks = duration_cast<microseconds>(end-begin);
      myfile<<ticks.count()<<"";
      myfile<<"\n";

       begin = high_resolution_clock::now();
      call_jaja=(jaja)GetProcAddress(histDLL,"jaja");
      myfile<< "void,,";
(call_jaja)( &cont04,&cont14,&cont24);
       end = high_resolution_clock::now();
       ticks = duration_cast<microseconds>(end-begin);
      myfile<<ticks.count()<<"";
myfile<< ",,"<< cont04;
myfile<< ",,"<< cont14;
myfile<< ",,"<< cont24;
      myfile<<"\n";

      FreeLibrary(histDLL);
      }
return 0;
}