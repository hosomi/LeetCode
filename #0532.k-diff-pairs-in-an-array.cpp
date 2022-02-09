class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        unordered_map<int, int> counter;
        int result = 0;
        for (const int& num : nums) {
            if (counter.find(num) == counter.end()) {
                if (counter.find(num-k) != counter.end()) {
                    ++result;
                }
                if (counter.find(num+k) != counter.end()) {
                    ++result;
                }
            } else if (counter[num] == 1) {
                if (k == 0) {
                    ++result;
                }
            }
            ++counter[num];
        }
        return result;
    }
};
