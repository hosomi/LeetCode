class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());
        for(int i = 1; i <= nums.size(); i++) {
            int l = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
            if (nums.size() - l == i) {
                return i;
            }
        }
        return -1;
    }
};
