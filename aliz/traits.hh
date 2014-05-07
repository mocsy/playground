#ifndef traits_hh
#define traits_hh

#include <map>

#include <iostream>

namespace traits
{

   template <class U>
   class AddTrait
   {
   public:
      template <typename T>
      void Add(std::string key, T & data);
   };

   template <class U>
   class GetTrait
   {
   public:
      template <typename T>
      T & Get(std::string key);
   };

   template <class U>
   class MapTrait
   {
   };

   template <>
   class MapTrait <GetTrait<class U> >
   {
   public:
      template <typename T>
      T &  Get(std::string key)
      {
         T t;
         return t;
      }
   private:
      std::map<std::string, std::string> mMap;
   };

   template <>
   class MapTrait <AddTrait<class U> >
   {
   public:
      template <typename T>
      void Add(std::string key, T & data)
      {
         return;
      }
   private:
      std::map<std::string, std::string> mMap;
   };

   template <class U>
   class MapTrait <AddTrait<GetTrait<U> > >
   {
   public:
      template <typename T>
      T &  Get(std::string key)
      {
         std::cout << "hagf_Get" << std::endl;
         return (mMap.find(key))->second;
      }
      template <typename T>
      void Add(std::string key, T & data)
      {
         std::cout << "hagf_Add" << std::endl;
         return;
      }
   private:
      std::map<std::string, std::string> mMap;
   };

   template<typename T>
   struct AddGetMap
   {
      typedef MapTrait<AddTrait<GetTrait<T> > > type;
   };

}

#endif
