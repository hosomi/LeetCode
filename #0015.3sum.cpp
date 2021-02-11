class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector <vector<int>> result;
        int size = nums.size();
        int low;
        int high;
        int sum;
        for (int i = 0; i < size - 2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                low = i+1;
                high = size -1;
                sum = 0 - nums[i];
                while (low < high) {
                    if (nums[low] + nums[high] == sum) {
                        result.push_back({nums[i],nums[low],nums[high]});
                        while (low < high && nums[low] == nums[low+1]) {
                            low++;
                        }
                        while (low < high && nums[high] == nums[high-1]) {
                            high--;
                        }
                        low++;
                        high--;
                    } else if(nums[low] + nums[high] > sum) {
                        high--;
                    } else {
                        low++;
                    }
                }
            }
        }
        return result;
    }
};
