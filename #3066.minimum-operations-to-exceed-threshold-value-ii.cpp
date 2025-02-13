class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto num : nums) {
            pq.push(num);
        }

        int ans = 0;
        while (pq.size() && pq.top() < k) {
            long minNum = pq.top();
            pq.pop();

            long nextMinNum = pq.top();
            pq.pop();
            
            pq.push(2 * minNum + nextMinNum);
            ans++;
        }
        return ans;
    }
};
