#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class IBase
{};

class BaseOne : public IBase
{
public:
   int i;
   virtual ~BaseOne(){}
};

class BaseTwo : public IBase
{
public:
   int j;
   virtual ~BaseTwo(){}
};

class BaseThree
{
public:
   int k;
   virtual ~BaseThree(){}
};

template <class Base> class Mixin : public Base
{
   //
};

#if __cplusplus > 199711L
template<class Base, class... Classes> class VariadicMixin : public Base, public Classes...
{
   //
};
#endif

int main(int argc, const char* argv[])
{
   Mixin<BaseOne> m1;
   Mixin<BaseTwo> m2;
   Mixin<IBase> * m3 = (Mixin<IBase>*)new Mixin<BaseTwo>;
   //Mixin<vector<unsigned> > mVect(100);
   //vector<unsigned> vect(100);

   cout << m1.i << endl;
   cout << m2.j << endl;
   cout << ((Mixin<BaseTwo>*)m3)->j << endl;
#if __cplusplus > 199711L
   cout << "Got C++11!" << endl;
   VariadicMixin<BaseOne, BaseTwo, BaseThree> m4;
   cout << m4.i << endl;
   cout << m4.j << endl;
   cout << m4.k << endl;
#endif

   delete m3;
}
