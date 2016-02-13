#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <halfflipfop2>

using namespace std;

int main(int argc, const char* argv[])
{

   halfflipfop2 hf;
   sts::pair<bool,bool> res = hf.decide_sr(0,0);
   cout << res << endl;


}
