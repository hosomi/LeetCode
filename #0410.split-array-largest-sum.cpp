class Solution {
public:
    int splitArray(vector<int>& nums, int m) {

        long long max = 0;
        long long sum = 0;
        for (long long num : nums) {
            max = std::max(max, num);
            sum += num;
        }
        
        long long left = max;
        long long right = sum;
        long long mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (isValid(nums, m, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return (int)left;
    }

private:
    bool isValid(vector<int>& nums, int m, long long maxSubSum) {

        long long subSum = 0;
        int count = 1; 
        for (int num : nums) {
            subSum += num;
            if (subSum > maxSubSum) {
                subSum = num;
                count++;
                if (count > m) {
                    return false;
                }
            }
        }
        return true;
    };
};
