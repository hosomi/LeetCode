class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; ++i){
            pq.push({nums[i], i + 1});
        }

        int result = 0;
        int modulo = 1e9 + 7;
        for (int i = 1; i <= right; ++i) {
            pair<int, int> p = pq.top(); pq.pop();
            
            if (i >= left) {
                result = (result + p.first) % modulo;
            }
            
            if (p.second < n) {
                pq.push({p.first + nums[p.second++], p.second});
            }
        }
        
        return result;
    }
};
