#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "service.hh"
#include "aliz.hh"

// using namespace std;
using namespace aliz;
// using namespace traits;

// class Memo
// {
//    //
// };

int main(int argc, const char* argv[])
{
   int x = 8;
   std::cout << (TypeToType<unsigned>::OriginalType)x << std::endl;  //8
   ++x;
   std::cout << (TypeToType<unsigned>::OriginalType)x << std::endl;  //9
   ++x;
   std::cout << static_cast<AutoReference<unsigned>::InnerType >(x) << std::endl;   //10
   AutoReference<int> airX(x);
   (*airX)++;
   std::cout << *airX << std::endl;                   //11
   ++x;
   std::cout << x << std::endl;                                      //12

   Service srv;
   srv.SerializeTrigger();
}

