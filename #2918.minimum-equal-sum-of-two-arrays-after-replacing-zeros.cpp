class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {

        long long sum1 = 0;
        long long sum2 = 0;
        long long zeroes1 = 0;
        long long zeroes2 = 0;
        for (int num : nums1) {
            sum1 += num;
            zeroes1 += num == 0;
        }

        for (int num : nums2) {
            sum2 += num;
            zeroes2 += num == 0;
        }
        
        if (zeroes1 == 0 && zeroes2 == 0) {
            if (sum1 == sum2) {
                return sum1;
            }
            return -1;
        }
        
        if (zeroes2 == 0) {
            return sum1 + zeroes1 > sum2 ? -1 : sum2;
        }

        if (zeroes1 == 0) {
            return sum2 + zeroes2 > sum1 ? -1 : sum1;
        }
        
        return std::max(sum1 + zeroes1, sum2 + zeroes2);
    }
};
