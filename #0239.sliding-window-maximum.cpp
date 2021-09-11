class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int size = nums.size();
        std::deque<pair<int, int>> deq;
        vector<int> result(size - k + 1);
        for (int i = 0; i < size; i++) {
            while ((deq.size() > 0) && (nums[i] > deq.back().first)) {
                deq.pop_back();
            }
            deq.push_back(make_pair(nums[i], i));
            
            if (deq.front().second == i - k) {
                deq.pop_front();
            }

            if (i >= k - 1) {
                result[i - (k - 1)] = deq.front().first;
            }
        }
        return result;
    }
};
