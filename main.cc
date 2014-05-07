#include <iostream>
#include <vector>

//#include <stdio.h>

//build with g++ -fno-rtti -finstrument-functions main.cc 
//addr2line -e ./a.out 0x4008f8

using namespace std;

extern "C"
{
   void __cyg_profile_func_enter (void *, void *) __attribute__((no_instrument_function));
   void __cyg_profile_func_exit (void *, void *) __attribute__((no_instrument_function));
}

#define printp()\
   printf("%s %p\n", __FUNCTION__, &__FUNCTION__)

#define x notmain

int notmain()
{
//    printf("%s %p\n", __func__, __func__);
//    printf("%s %p\n", __FUNCTION__, __FUNCTION__);
//    printp();
//    printf("%s %p\n", "notmain", &notmain);
//    printf("%s %p\n", "x", &x);
//    printf("fp0: %p\n", __builtin_frame_address(0));
//    printf("rp0: %p\n", __builtin_return_address(0));
//    printf("fp1: %p\n", __builtin_frame_address(1));
//    printf("rp1: %p\n", __builtin_return_address(1));
}

#undef x
#define x main

int main()
{

    printf("%s %p\n", __func__, &__func__);
//    printf("%s %p\n", __FUNCTION__, __FUNCTION__);
//    printp();
//    printf("%s %p\n", "main", &main);
//    printf("%s %p\n", "x", &x);
//    printf("fp0: %p\n", __builtin_frame_address(0));
//    printf("rp0: %p\n", __builtin_return_address(0));
//    printf("fp1: %p\n", __builtin_frame_address(1));
//    printf("rp1: %p\n", __builtin_return_address(1));

   int i =1;
   for (;i>0;--i)
   {
      notmain();
   }


   //C++11 supported in gcc 4.4 and up
   //std::vector<int> v = { 1,2,3,4,5,6,7,8 };
   //C++11 ?
   //for(auto e : v)
   //{
   //   cout << e << endl;
   //}

   return 0;
}

extern "C"
{
   void __cyg_profile_func_enter(void *this_fn, void *call_site)
   {
      printf("enter: %p %p\n", this_fn, call_site);
   }
   void __cyg_profile_func_exit(void *this_fn, void *call_site)
   {
      printf("exit: %p %p\n", this_fn, call_site);
   }
}

