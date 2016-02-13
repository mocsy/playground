#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "halfflipflop2.hh"

using namespace std;

int main(int argc, const char* argv[])
{

   clementine::halfflipflop2 hf;
   bool in1 = 0;
   bool in2 = 0;
   cout << "In: " << in1 << in2 << endl;
   std::pair<bool,bool> res = hf.decide_sr(in1,in2);
   cout << "Out: " << res.first << res.second << endl;

   in1 = 0;
   in2 = 1;
   cout << "In: " << in1 << in2 << endl;
   res = hf.decide_sr(in1,in2);
   cout << "Out: " << res.first << res.second << endl;
   
   in1 = 1;
   in2 = 0;
   cout << "In: " << in1 << in2 << endl;
   res = hf.decide_sr(in1,in2);
   cout << "Out: " << res.first << res.second << endl;
   
   in1 = 1;
   in2 = 1;
   cout << "In: " << in1 << in2 << endl;
   res = hf.decide_sr(in1,in2);
   cout << "Out: " << res.first << res.second << endl;
}
