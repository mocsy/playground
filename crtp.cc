#include <iostream>
#include <list>

using namespace std;

class UseMe_
{
public:
   virtual void use() {};
};

template <class WHO>
class UseMe : public UseMe_
{
public:
   void use()
   {
      cout << __PRETTY_FUNCTION__ << endl;
   }
};

#define UseMe UseMe<__typeof__(this)>

class UserA
{
public:
   void use()
   {
      UseMe u;
      u.use();
   }
};

class UserB
{
public:
   typedef std::list<UseMe_> UseMes;
   void use()
   {
      UseMe u;
      u.use();
      UseMes ul;
      ul.push_back(u);
      ul.front().use();
   }
};

int main(int argc, const char* argv[])
{
   UserA a;
   a.use();
   UserB b;
   b.use();
}
