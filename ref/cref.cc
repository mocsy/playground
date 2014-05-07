#include <iostream>
#include <cstring>
#include <sstream>

static int x = 0;

void testConstRef(const std::string& s)
{
   ++x;
   std::stringstream ss;
   ss << s << x;
   //s = ss.str();
}

int main(int argc, const char* argv[])
{
   std::string str("0");
   testConstRef(str);
   //std::cout << x << std::endl;
}
