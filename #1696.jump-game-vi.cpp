class Solution {
public:
    int maxResult(vector<int>& nums, int k) {

	    int size = nums.size();
        std::deque<pair<int, int>> dq;
        dq.push_back({0, nums[0]});
        for (int i = 1; i < size; ++i) {
            int cur = nums[i] + dq.front().second;
            while (!dq.empty() && cur >= dq.back().second) {
                dq.pop_back();
            }
            
            dq.push_back({i, cur});
            if (dq.front().first <= i - k) {
                dq.pop_front();
            }
        }
        return dq.back().second;
    }
};
