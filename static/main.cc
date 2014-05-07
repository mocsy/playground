#include <iostream>
// #include <vector>
// #include <algorithm>
// #include <fstream>

#include "static.hh"
#include <cstring>

using namespace std;

#define PERR "alma"
#ifdef PERR
#define PERR_ PERR
#undef PERR
#define PERR "korte"
#endif

int main(/*int argc, const char* argv[]*/)
{
   StaticStringConverter a;
   //std::string temp("gsds");
   cout << a.uintToStr(0x59) << endl;

   cout << a.getUnsigned<unsigned>(0x656) << endl;

   char * v = new char[sizeof(unsigned)];
   memset(v, 0, sizeof(unsigned));
   cout << v << endl;

   cout << PERR << endl;
   cout << PERR_ << endl;

   return 0;
}
