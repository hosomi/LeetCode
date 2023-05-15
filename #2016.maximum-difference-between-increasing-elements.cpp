class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int front = nums.front();
        int result = 0;
        for (const int &it : nums) {
            front = std::min(front, it);
            result = std::max(result, it - front);
        }
        return result == 0 ? -1 : result;
    }
};
