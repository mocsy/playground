
namesapce clementine {

    /// 0. convert input to input matrix
    /// 1. throw half of input matrix
    /// 2. call a decide function
    /// 3. profit
    /// 
    /// has two coordinates: A and B just like Vector2
    class halfflipfop2 {
        public:
        halfflipfop2(){};
        
        std::pair<bool,bool> decide_sr(bool S, bool R);
        std::pair<bool,bool> decide_d(bool D);
        std::pair<bool,bool> decide_dg(bool D, bool G);
    }
}