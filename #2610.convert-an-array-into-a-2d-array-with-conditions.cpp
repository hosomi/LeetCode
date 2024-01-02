class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        int size = nums.size();
        int max = 0;
        unordered_map<int, int> um;
        for (int i = 0; i < size; i++) {
            um[nums[i]]++;
            max = std::max(max, um[nums[i]]);
        }

        vector<vector<int>> results(max);
        for (auto m : um) {
            for (int i = 0 ; i < m.second; i++) {
                results[i].push_back(m.first);
            }
        }
        return results;
    }
};
