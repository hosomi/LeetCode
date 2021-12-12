class Solution {
public:
    bool canPartition(vector<int>& nums) {

        std::bitset<10001> bits(1);
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        for (auto num : nums) {
            bits |= bits << num;
        }
        return !(sum & 1) && bits[sum >> 1];
    }
};
