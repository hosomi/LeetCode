class Solution {
public:
    int minimizeXor(int num1, int num2) {

        int ct = __builtin_popcount(num2);
        int ans = 0;
        for (int i = 31; i > -1 && ct; --i) {
            if ((num1>>i) & 1) {
                ans |= (1<<i);
                ct--;
            }
        }

        for (int j = 0; j < 32 && ct; ++j) {
            if (!((ans>>j) & 1)) {
                ans |= (1<<j);
                ct--;
            }
        }
        return ans;
    }
};
