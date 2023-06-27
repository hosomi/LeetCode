class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        int s1 = nums1.size();
        int s2 = nums2.size();
        priority_queue<pair<long long, pair<long long, long long>>,
            vector<pair<long long, pair<long long,long long>>>,
                greater<pair<long long, pair<long long, long long>>>> pq;

        pq.push({ nums1[0] + nums2[0], { 0, 0 }});
        vector<vector<int>> result;
        while (k-- && pq.size()) {
            auto it = pq.top();
            pq.pop();
            result.push_back({ nums1[it.second.first], nums2[it.second.second] });
            if (it.second.first + 1 < s1) {
                pq.push({nums1[it.second.first + 1] + nums2[it.second.second],
                    { it.second.first+1,it.second.second }});
            }

            if (it.second.first == 0 && it.second.second + 1 < s2) {
                pq.push({nums1[it.second.first] + nums2[it.second.second + 1],
                    { it.second.first, it.second.second + 1 }});
            }
        }
        return result;
    }
};
