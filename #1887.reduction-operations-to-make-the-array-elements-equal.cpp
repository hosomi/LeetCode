class Solution {
public:
    int reductionOperations(vector<int>& nums) {

         sort(nums.begin() , nums.end());
         
         int size = nums.size();
         int cnt = 0; 
         int result = 0;
         for (int i = 1 ; i < size ; i++) {
            result += (nums[i] != nums[i - 1]) ? ++cnt : cnt;  
         }
         return result; 
    }
};
