class Solution {
public:
    int hammingWeight(uint32_t n) {

        int result = 0;
        while(n > 0) {
            if (n&1 == 1) {
                result++;
            }
            n >>= 1;
        }
        return result;
    }
};
