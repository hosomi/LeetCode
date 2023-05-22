class Solution {
public:
    int getSum(int a, int b) {
        
        while (a != 0 && b != 0) {
            uint and_ = a & b;
            uint xor_ = a ^ b;
            a = and_ << 1;
            b = xor_;
        }

        return a != 0 ? a : b;
    }
};
