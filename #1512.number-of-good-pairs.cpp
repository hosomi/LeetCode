class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        int counter[101] = {0};
        int result = 0;
        for (auto i : nums) {
            result += counter[i];
            counter[i] += 1;
        }
        return result;
    }
};
