#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

#define GCC_VERSION (__GNUC__ * 10000 \
+ __GNUC_MINOR__ * 100 \
+ __GNUC_PATCHLEVEL__)

#define __MVERSION__ 1
#define __MINOR__ 0
#define __PATCHLEVEL__ 0
#define __REVISION__ 0
#define __BUILD__ __DATE__


int main(int argc, const char* argv[])
{

   printf("v: %s VER: %u.%u.%u.%u.%s", __VERSION__, __MVERSION__, __MINOR__, __PATCHLEVEL__, __REVISION__, __BUILD__);

   //cout << GCC_VERSION <<endl;

   //unsigned int i = 0xFFFFFFFF;
   //int i = 0x7FFFFFFF;
   //cout << i << endl;
   //i += 1;
   //i -= 2;
   //cout << i << endl;

   int i = -9;

   if( ( i % 2 ) == 0) cout << "Even" << endl;
   if( ( i % 2 ) == 1) cout << "Odd" << endl;
   cout << i % 2 << endl;

   cout<< __FILE__ << endl;
}
