class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        
        int count = 0;
        int i = 0;
        while (i < nums.size()){
            count++;
            int start = nums[i];
            while (i < nums.size() && nums[i] - start <= k) {
                i++;
            }
        }
        return count;
    }
};
