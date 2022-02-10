class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        unordered_map<int,int> sum;
        sum[0]++;
        vector<int> v(size, 0);
        v[0] = nums[0];
        sum[v[0]]++;

        int result = 0;
        if (v[0] == k) {
            result++;
        }

        for (int i = 1; i < size; i++) {
            v[i] = v[i-1] + nums[i];
            result += sum[v[i] - k];
            sum[v[i]]++;
        }
        return result;
    }
};
