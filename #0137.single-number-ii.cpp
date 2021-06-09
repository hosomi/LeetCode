class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result = 0;
        int sum;
        for (int i = 0; i < 32; i++) {
            sum = 0;
            for (int num : nums) {
                sum = sum + ((num >> i) & 1);
            }
            result += sum % 3 ? (1 << i) : 0;
        }
        return result;
    }
};
