class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int size = nums.size();
        int first = 0;
        int last = size - 1;
        while(first <= last){

            int mid = (first+last) >> 1;
            if (nums[mid] < target) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }

        if (first >= size || nums[first] != target){
            return {-1, -1};
        }

        vector<int> result = {first};
        first = 0;
        last = size - 1;
        int index;
        while (first <= last) {
            index = (first + last) >> 1;
            if (nums[index] > target){
                last = index - 1;
            } else {
                first = index + 1;
            }
        }

        result.push_back(last);
        return result;
    }
};
