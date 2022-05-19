class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {

        const int numSize = nums.size();
        const int mSize = multipliers.size();
        std::reverse(multipliers.begin(), multipliers.end());
        vector<int> cur(mSize, 0);
        vector<int> prev(mSize, 0);
        int len = numSize - (mSize - 1);
        for (int i = numSize - len; i >= 0; --i) {
            cur[0] = std::max(nums[i] * multipliers[0],
                              nums[i + len - 1] * multipliers[0]);

            for (int j = 1; j <= (numSize - len - i); ++j) {                
                cur[j] = std::max(nums[i] * multipliers[j] + prev[j-1],
                                  nums[i + len - 1 + j] * multipliers[j] + cur[j-1]); 
            }
            std::swap(cur, prev);
        }
        
        return prev.back();
    }
};
