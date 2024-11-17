class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        deque<pair<int,long long>> dq;
        long long sum = 0;
        int result = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum >= k) {
                result = std::min(result, i + 1);
            }

            while (dq.size() and sum - dq.front().second >= k){
                result = std::min(result,i - dq.front().first);
                dq.pop_front();
            }

            while (dq.size() and dq.back().second >= sum){
                dq.pop_back();
            }
            dq.push_back({i ,sum});
        }
        return result == INT_MAX ? -1 : result;
    }
};
