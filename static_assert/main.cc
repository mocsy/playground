#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "static_assert.hpp"

using namespace std;

#define GCC_VERSION (__GNUC__ * 10000 \
+ __GNUC_MINOR__ * 100 \
+ __GNUC_PATCHLEVEL__)

int main(int argc, const char* argv[])
{
   //cout << GCC_VERSION <<endl;

   //unsigned int i = 0xFFFFFFFF;
   //int i = 0x7FFFFFFF;
   //cout << i << endl;
   //i += 1;
   //i -= 2;
   //cout << i << endl;

   int i = -9;

   //BOOST_STATIC_ASSERT< sizeof(int) == 1 >;
   BOOST_STATIC_ASSERT(sizeof(int) == 0);
}
