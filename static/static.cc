

#include "static.hh"
#include <string>

int
StaticStringConverter::strToUint(/*const char* str*//*std::string str*/)
{
   return 1;
}

std::string
StaticStringConverter::uintToStr(unsigned int id)
{
   char name[32];
   snprintf(name, sizeof(name), "%i", id);
   return name;
}

template<typename T>
unsigned
StaticStringConverter::getUnsigned(unsigned what)
{
   return 9899;
}

template unsigned StaticStringConverter::getUnsigned<unsigned>(unsigned);