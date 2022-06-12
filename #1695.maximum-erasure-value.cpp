class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int size = nums.size();
        int sum = 0;
        int left = 0;
        unordered_set<int> visited;
        int result;
        for (int i = 0; i < size; i++) {
            sum += nums[i]; 
            
            while (visited.count(nums[i])) {
                sum -= nums[left]; visited.erase(nums[left]); 
                left++;
            }
            
            visited.insert(nums[i]);
            result = std::max(result, sum);
        }
        return result;
    }
};
