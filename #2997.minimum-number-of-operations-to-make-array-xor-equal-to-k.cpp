class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int xo = 0;
        for (auto i : nums) {
            xo ^= i;
        }

        k ^= xo;
        int result = 0;
        while (k > 0) {
            result += (k & 1);
            k = k >> 1;
        }
        return result;
    }
};
