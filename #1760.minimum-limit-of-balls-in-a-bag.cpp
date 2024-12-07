class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {

        int low = 1;
        int high = 1e9;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int splitOperations = 0;
            for (auto num: nums){
                splitOperations += (num - 1) / mid;
            }
            if (splitOperations > maxOperations) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
