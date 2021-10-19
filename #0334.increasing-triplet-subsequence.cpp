class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int min = INT_MAX;
        int mid = INT_MAX;
        for (int num : nums) {
            if (num <= min) {
                min = num;
            } else if (num <= mid) {
                mid = num;
            } else {
                return true;
            }
        }
        return false;
    }
};
