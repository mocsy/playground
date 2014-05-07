#include <iostream>
#include <cstring>
#include <sstream>

static int z = 0;

void testValue(std::string s)
{
   ++z;
   std::stringstream ss;
   ss << s << z;
   //s = ss.str();
}

int main(int argc, const char* argv[])
{
   std::string str("0");
   testValue(str);
   //std::cout << z << std::endl;
}
