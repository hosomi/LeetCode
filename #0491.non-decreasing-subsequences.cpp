class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        int size = nums.size();
        vector<vector<int>> result;
        vector<vector <vector<int>>> table(size);
        for(int i = 0; i != size; i++) {
        for(int j = i + 1; j != size; j++)  
            if (nums[i] <= nums[j]) {
                table[j].push_back({nums[i]});
                for (int k = 0; k != table[i].size(); k++) {
                    table[j].push_back(table[i][k]);
                    table[j].back().push_back(nums[i]);
                }
            }
            for (int k = 0; k != table[i].size(); k++) {
                result.push_back(table[i][k]);
                result.back().push_back(nums[i]);
            }
        }
        
        std::sort(result.begin(), result.end());
        result.resize(
            distance(result.begin(),
            unique(result.begin(), result.end()))
        );
        return result;
    }
};
