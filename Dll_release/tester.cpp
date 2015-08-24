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
int main(int argc,char **argv)
{
function2 call_function2(0);
function1 call_function1(0);
const char* cont="output.txt";
std::ofstream myfile;
myfile.open(cont);
auto  begin = high_resolution_clock::now();
auto end = high_resolution_clock::now();
auto   ticks = duration_cast<microseconds>(end-begin);
histDLL= LoadLibrary("function.dll");
    if (histDLL != NULL){
       begin = high_resolution_clock::now();
      call_function2=(function2)GetProcAddress(histDLL,"function2");
      myfile<<(call_function2)( 24)<<",,";
       end = high_resolution_clock::now();
auto       ticks = duration_cast<microseconds>(end-begin);
      myfile<<ticks.count()<<"\n";

       begin = high_resolution_clock::now();
      call_function1=(function1)GetProcAddress(histDLL,"function1");
      myfile<<(call_function1)( 23)<<",,";
       end = high_resolution_clock::now();
       ticks = duration_cast<microseconds>(end-begin);
      myfile<<ticks.count()<<"\n";

      FreeLibrary(histDLL);
      }
return 0;
}