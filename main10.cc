#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

//template <typename T>
class MyClass
{
public:
   template <class T>
   void setImyObject(T * mob);
   template <class T>
   void setSpecObject(T * specobj);
};

class ImyObject
{
public:
   virtual ~ImyObject()
   {}
};

class OkObject : public ImyObject
{};

class SpecObject : public ImyObject
{};

template <typename T>
struct IsSpecObject { static bool const value = false; };

template <>
struct IsSpecObject<SpecObject> { static bool const value = true; };


template<class ImyObject>
   void
   MyClass::setImyObject(ImyObject * mob)
   {
      static_assert(IsSpecObject<ImyObject>::value != true, "Can not use this for SpecObject!");
   }


template<class SpecObject>
   void
   MyClass::setSpecObject(SpecObject * specobj)
   {
      //do something with SpecObject
   }

int main(int argc, const char* argv[])
{
   MyClass mc;
   ImyObject * s = new SpecObject;
   mc.setImyObject(s);
}
