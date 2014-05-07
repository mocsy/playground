#include <iostream>
#include "stacktrace.h"

#include <assert.h>

//#include "bsd_stacktrace.h"
//compile with: -rdynamic

void method_()
{
   //log_stacktrace();
   print_stacktrace();
}
void method4()
{
   printf("%s\n",__func__);
   method_();
}
void method3()
{
   printf("%s\n",__func__);
   method4();
}
void method2()
{
   printf("%s\n",__func__);
   method3();
}
void method1()
{
   printf("%s\n",__func__);
   method2();
}

int main(int argc, const char* argv[])
{
   int x = 10;
   std::cout << x << std::endl;
   method1();
}
