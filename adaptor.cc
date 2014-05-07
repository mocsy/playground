#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Base
{
public:
   virtual ~Base(){}
};

class Adapting : public Base
{
public:
   int x;
   void test()
   {
      Adaptor a;
      a.adapt(this);
   }
private:
   class Adaptor
   {
   public:
      void adapt(Adapting * adaptingInstance)
      {
         adaptingInstance->x = 10;
      }
   };
};


int main(int argc, const char* argv[])
{
   Base b;
   Adapting t;
   cout << t.x << endl;
   t.test();
   cout << t.x << endl;
}
