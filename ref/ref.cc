#include <iostream>
#include <cstring>
#include <sstream>

static int y = 0;

void testRef(std::string& s)
{
   ++y;
   std::stringstream ss;
   ss << s << y;
   //s = ss.str();
}

int main(int argc, const char* argv[])
{
   std::string str("0");
   testRef(str);
   //std::cout << y << std::endl;
}
