class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int,int> m;
        int sum = 0;
        int count = 0;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum - goal;
            count += m[rem];
            m[sum]++;
        }
        return count;
    }
};
