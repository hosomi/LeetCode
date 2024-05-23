class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {

        unordered_map<int, int> m;
        beautifulSubsets(nums, m, 0, k);
        return result;
    }

private:
    int result = 0;
    void beautifulSubsets(vector<int>& nums,
        unordered_map<int, int> &m, int start,int k) {

        for (int i = start; i < nums.size(); i++) {
            if (m[nums[i] - k] == 0 && m[nums[i] + k] == 0) {
                result++;
                m[nums[i]]++;
                beautifulSubsets(nums, m, i + 1, k);
                m[nums[i]]--;
            }
        }
    }
};
