#include <halfflipfop2>
#include <utility>

namesapce clementine {
    
    std::pair<bool,bool> halfflipfop2::decide_sr(bool S, bool R)
    {
        static bool Q, Qn = 0;
        if (S == 1) {
            if(R == 0) {
                Q = 1;
                Qn = !Q;
            }
            else {
                Q = -1;
                Qn = -1;
            }
        }
        else {
            if(R ==0) {
                Q = Q;
                Qn = Qn;
            }
            else {
                Q = 0;
                Qn = !Q;
            }
        }
        return std::make_pair(Q, Qn);
    }
    
    std::pair<bool,bool> halfflipfop2::decide_d(bool D)
    {
        static bool Q = D;
        static bool Qn = !D;
        return std::make_pair(Q, Qn);
    }
    
    std::pair<bool,bool> halfflipfop2::decide_dg(bool D, bool G)
    {
        static bool Q, Qn = 0;
        if (D == 1) {
            if(G == 0) {
                Q = Q;
                Qn = Qn;
            }
            else {
                Q = 1;
                Qn = !Q;
            }
        }
        else {
            if(G ==0) {
                Q = Q;
                Qn = Qn;
            }
            else {
                Q = 0;
                Qn = !Q;
            }
        }
        return std::make_pair(Q, Qn);
    }
}