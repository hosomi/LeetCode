class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        unordered_map<int,int> um;
        for (auto &i : nums) {
            um[i]++;
        }

        int result = 0;
        for (auto &m : um) {
            int val = m.second;
            if (val == 1) {
                return -1;
            }

            result += val % 3 != 0 ? (val / 3) + 1 : val / 3;
        }
        return result;
    }
};
