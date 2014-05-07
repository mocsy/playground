#ifndef aliz_hh
#define aliz_hh

namespace aliz
{
   struct ITypeToType {};
   template<typename T>
   struct TypeToType : public ITypeToType
   {
     typedef T OriginalType;
   };

   namespace types
   {
      template<typename T>
         unsigned _typeID() { return 0; }
      template<>
         unsigned _typeID<bool>() { return 2; }
      template<>
         unsigned _typeID<char>() { return 3; }
      template<>
         unsigned _typeID<char*>() { return 4; }
      template<>
         unsigned _typeID<double>() { return 5; }
      template<>
         unsigned _typeID<int>() { return 6; }
      template<>
         unsigned _typeID<long long>() { return 7; }
      template<>
         unsigned _typeID<unsigned char>() { return 8; }
      template<>
         unsigned _typeID<unsigned char*>() { return 9; }
      template<>
         unsigned _typeID<unsigned>() { return 10; }
      template<>
         unsigned _typeID<unsigned long long>() { return 11; }
      template<>
         unsigned _typeID<std::string>() { return 12; }
   }

   struct AutoReferenceBase
   {
      virtual unsigned typeID() = 0;
   };
   template <class U>
   struct AutoReference : public AutoReferenceBase
   {
      typedef U InnerType;
      AutoReference()
         :mObject(0)
      {}
      AutoReference(U& obj)
         :mObject(obj)
      {}
      U& operator*()
      {
         return mObject;
      }
      U* operator->()
      {
         return &mObject;
      }
      virtual unsigned typeID() { return types::_typeID<U>(); }
   private:
      U& mObject;
   };

   template <class T> struct Add;

   struct IAlizTrait
   {
      virtual void RegisterMembers(aliz::Add<std::vector<AutoReferenceBase*> >&) = 0;
   };

   template <class C>
   struct Add
   {
      Add(C& container) : mContainer(container) {}
//       bool operator()(std::string key, void * data)
//       {
//          std::cout << "Add->operator () void *" << std::endl;
//          return true;
//       }
      // not specialization, just overload
      bool operator()(std::string key, int & data)
      {
         std::cout << "Add->operator () int &" << std::endl;
         AutoReference<int>* iAr = new AutoReference<int>(data);
//          std::cout << &iAr << " " << *iAr << std::endl;
         mContainer.push_back(iAr);
         return true;
      }
      bool operator()(std::string key, unsigned & data)
      {
         std::cout << "Add->operator () unsigned &" << std::endl;
         AutoReference<unsigned>* iAr = new AutoReference<unsigned>(data);
         mContainer.push_back(iAr);
         return true;
      }
      bool operator()(std::string key, bool & data)
      {
         std::cout << "Add->operator () bool &" << std::endl;
         AutoReference<bool>* iAr = new AutoReference<bool>(data);
         mContainer.push_back(iAr);
         return true;
      }
      bool operator()(std::string key, std::string & data)
      {
         std::cout << "Add->operator () std::string &" << std::endl;
         AutoReference<std::string>* iAr = new AutoReference<std::string>(data);
         mContainer.push_back(iAr);
         return true;
      }
      bool operator()(std::string key, IAlizTrait & data)
      {
         std::cout << "Add->operator () IAlizTrait &" << std::endl;
         data.RegisterMembers(*this);
         return true;
      }
   private:
      C& mContainer;
   };

   template <class T>
   struct AlizTrait : public IAlizTrait
   {
      virtual void RegisterMembers(aliz::Add<std::vector<AutoReferenceBase*> >&) = 0;
      void SerializeTrigger()
      {
         std::vector<AutoReferenceBase*> tmpVect;
         aliz::Add<std::vector<AutoReferenceBase*> > adder(tmpVect);
         static_cast<T*>(this)->RegisterMembers(adder);
         std::cout << tmpVect[0]->typeID() << std::endl;
         std::cout << tmpVect[1]->typeID() << std::endl;
         std::cout << tmpVect[2]->typeID() << std::endl;
      }
      void DeserializeTrigger()
      {
         std::vector<AutoReferenceBase*> tmpVect;
         aliz::Add<std::vector<AutoReferenceBase*> > adder(tmpVect);
         static_cast<T*>(this)->RegisterMembers(adder);
      }
   };
}

#endif //aliz_hh
