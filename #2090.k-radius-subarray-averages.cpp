class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        int size = nums.size();
        vector<long long> sums(size, 0);
        for(int i=0; i<size; i++) {
            sums[i] = nums[i] + ((i == 0) ? 0 : sums[i - 1]); 
        }

        vector<int> results(size, -1);
        for(int i = k; i <= size - k - 1; i++) {
            results[i] = (sums[i + k] - ((i - k - 1) < 0 ? 0 : sums[i - k - 1])) / (2 * k + 1);
        }
        return results;
    }
};
