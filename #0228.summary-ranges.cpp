class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        int size = nums.size();
        vector<string> result;
        if (size == 0) {
            return result;
        }

        int index;
        for (int i = 0; i < size; i++) {
            index = nums[i];
            while (i + 1 < size && nums[i] != INT_MAX && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            if (index == nums[i]) {
                result.push_back(to_string(index));
            } else {
                result.push_back(to_string(index) + "->" + to_string(nums[i]));
            }
        }
        return result;
    }
};
