#include <iostream>
#include <cstring>
#include <sstream>

void testConstRef(const std::string& s);
void testRef(std::string& s);
void testValue(std::string s);

int main(int argc, const char* argv[])
{
   std::string str("0");
   unsigned num = 1000000;
   unsigned cc =0;
   while(cc < num)
   {
      testConstRef(str);
      ++cc;
   }
   cc =0;
   while(cc < num)
   {
   testRef(str);
      ++cc;
   }
   cc =0;
   while(cc < num)
   {
   testValue(str);
      ++cc;
   }
   //std::cout << x << std::endl;
}

#define main crefmain
#include "cref.cc"
#undef main
#define main refmain
#include "ref.cc"
#undef main
#define main valmain
#include "val.cc"
#undef main
