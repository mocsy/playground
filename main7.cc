#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

#include <iostream>

class A
{
public:
   int x;
   int y;
   
   A(int v) : x(v), y(v) {}
   
   A& operator=(int v);
};

A& A::operator=(int v)
{
   x = 2*v;
   y = 2*v;
   return *this;
}

class B : public A
{
public:
   int z;
   
   B(int v) : A(v), z(v) {}
};

int main()
{
   B b(20);
   
   b = 30;
   
   std::cout << b.x << ", " << b.y << ", " << b.z << std::endl;
   
   return 0;
}
