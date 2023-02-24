class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int64_t size = nums1.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < size; i++) {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.begin(), v.end());
        
        int64_t s = 0;
        int64_t result = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = size - 1; i >= 0; i--) {
            pq.push(v[i].second);
            s += v[i].second;
            if (pq.size() > k) {
                s -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                result = max(result, v[i].first * s);
            }
        }
        return result;
    }
};
