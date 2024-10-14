class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        long long result = 0;
        priority_queue<int> pq = {nums.begin(), nums.end()};
        for (int i = 0; i < k; i++) {
            int top = pq.top();
            pq.pop();
            result += top;
            pq.push(ceil(top / 3.0));
        }
        return result;
    }
};
