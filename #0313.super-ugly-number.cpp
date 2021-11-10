class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        int size = primes.size();
        int* nums = new int[n];
        memset(nums, 0, sizeof(int) * n);
        nums[0] = 1;
        int* p = new int[size];
        memset(p, 0, sizeof(int) * size);
        for (int i = 1; i < n; ++i) {
            int num = INT_MAX;
            for (int j = 0; j < size; ++j) {
                num = std::min(num, nums[p[j]] * primes[j]);
            }
            nums[i] = num;
            for (int j = 0; j < size; ++j) {
                if (num == nums[p[j]] * primes[j]) {
                    ++p[j]; 
                }
            }
        }
        return nums[n-1];
    }
};
