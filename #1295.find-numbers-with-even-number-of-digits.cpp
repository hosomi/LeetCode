class Solution {
public:
    int findNumbers(vector<int>& nums) {

        int even = 0;
        int result = 0;
        for (int num : nums) {

            even = 0;
            while (num) {
                num /= 10;
                even++;
            }
            
            if (even % 2 == 0) {
                result++;
            }
        }
        return result;
    }
};
