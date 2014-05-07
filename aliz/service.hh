#ifndef service_hh
#define service_hh

#include "aliz.hh"

struct MemberClass : public aliz::AlizTrait<MemberClass>
{
   void
      RegisterMembers(aliz::Add<std::vector<aliz::AutoReferenceBase*> >& adder)
   {
      adder("key1", mBool);
   }
private:
   bool mBool;
};

struct Service : public aliz::AlizTrait<Service>
{
   Service ()
      :mX(90)
   {}
   void
      RegisterMembers(aliz::Add<std::vector<aliz::AutoReferenceBase*> >& adder)
   {
      adder("key1", mStr);
//       adder("key2", mVect);
      adder("key3", mX);
      adder("key4", mY);
      adder("key5", mClass);
   }
private:
   std::string mStr;
   std::vector<int> mVect;
   int mX;
   unsigned mY;
   MemberClass mClass;
};

#endif