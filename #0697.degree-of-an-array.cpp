class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        int size = nums.size();
        int index = 0;
        int min = 0;
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for (int i = 0; i < nums.size(); i++) {
            if (m2.find(nums[i]) == m2.end()) {
                m2[nums[i]] = i;
            }
            
            m1[nums[i]]++;

            if (m1[nums[i]] > index) {
                index = m1[nums[i]];
                min = i - m2[nums[i]] + 1;
            } else if (m1[nums[i]] == index) {
                min = std::min(min, i - m2[nums[i]] + 1);
            }
        }
        return min;
    }
};
