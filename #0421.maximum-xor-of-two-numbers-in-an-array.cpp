class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        int result = 0;
        int bit = 0;
        unordered_set<int> s;
        for (int i = 31; i >= 0; i--) {
            s.clear();
            bit |= 1 << i;
            for (int num : nums) {
                s.insert(num & bit);
            }
            int tmp = result | (1 << i);
            for (int pre : s) {
                if (s.count(tmp ^ pre)) {
                    result = tmp;
                    break;
                }
            }
        }
        return result;
    }
};
