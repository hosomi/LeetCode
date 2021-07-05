class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int counter = 0;
        int result = 0;
        for (int num : nums) {
            if (counter == 0) {
                result = num;
            }
            counter += (num == result) ? 1 : -1;
        }
        return result;
    }
};
