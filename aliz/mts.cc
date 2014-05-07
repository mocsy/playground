#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

   template <class U>
   class ABase
   {};

   template <class U>
   class Working
   {};

   template <class U>
   class NotWorking
   {};

//------------------------------------

   class TestClass {};

   template <>
   class Working<TestClass>
   {
   public:
      template <typename T>
      void Get(T & data)
      {
         return;
      }
   };

   template <class U>
   class NotWorking<ABase<U> >
   {
   public:
      template <typename T>
      void Get(T & data)
      {
         return;
      }
   };

//------------------------------------

int main(int argc, const char* argv[])
{
   string tmpStr = "key";

   Working<TestClass> wtc;
   wtc.Get<string>(tmpStr);

   NotWorking<ABase<TestClass> > nwtc;
   nwtc.Get<string>(tmpStr);
}
