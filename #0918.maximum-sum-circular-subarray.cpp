class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int size = nums.size();
        vector<int> v(2 * size + 1, 0);
        for (int i = 0; i < 2 * size; i++) {
            v[i + 1] = v[i] + nums[i % size];
        }
        
        deque<int> dq;
        dq.push_back(0);
        int result = nums[0];
        for (int j = 1; j <= 2 * size; j++) {
            if (j - dq.front() > size) {
                dq.pop_front();
            }
            
            result = std::max(result, v[j] - v[dq.front()]);
            while (!dq.empty() && v[j] <= v[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(j);
        }
        return result;
    }
};
