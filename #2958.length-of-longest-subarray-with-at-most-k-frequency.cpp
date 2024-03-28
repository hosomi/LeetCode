class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        unordered_map<int,int> m;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int max = 0;
        while (i < n) {
            m[nums[i]]++;
            while (m[nums[i]] > k) {
                if (!--m[nums[j]]) {
                    m.erase(nums[j]);
                }
                j++;
            }
            max = std::max(max, i - j + 1);
            i++;
        }
        return max;  
    }
};
