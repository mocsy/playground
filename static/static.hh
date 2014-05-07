#ifndef StaticStringConverter_hh
#define StaticStringConverter_hh

#include <string>

class StaticStringConverter
{
public:
   StaticStringConverter(){};
   //int strToUint(/*const char* str*/);
   static int strToUint();

   static std::string uintToStr(unsigned int id);

   template<typename T>
   unsigned
   getUnsigned(unsigned what);
};

#endif