class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        if (sx == fx && sy == fy && t == 1) {
            return false;
        }

        return !(std::max(std::abs(fx-sx), std::abs(fy-sy)) > t);
    }
};
