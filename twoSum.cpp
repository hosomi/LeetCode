class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> ixs;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(ixs.find(complement) != ixs.end()){
                return vector<int> {i, ixs[complement]};
            }
            ixs[nums[i]] = i;
        }
        return vector<int> {};
    }
};
