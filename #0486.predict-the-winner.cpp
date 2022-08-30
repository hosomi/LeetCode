class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {

        int size = nums.size();
        if (size <= 2) {
            return true;
        }
        
        vector<vector<int>> result = 
            vector<vector<int>>(size, vector<int>(size, -1));
        for (int i = 1; i < size; i++) {
            for (int j = 0; j + i < size; j++) {
                int dist = j + i;
                if (i == 1) {
                    result[i][j] = std::max(nums[j], nums[dist]);
                    continue;
                }

                result[i][j] = std::max(
                    nums[j] + std::accumulate(nums.begin() + j + 1,
                          nums.begin() + dist + 1, 0) - result[i - 1][j + 1],
                    nums[dist] + std::accumulate(nums.begin() + j,
                          nums.begin() + dist, 0) - result[i - 1][j]);
            }
        }
        return result[size - 1][0] >=
            std::accumulate(nums.begin(), nums.end(), 0) / 2.0;
    }
};
