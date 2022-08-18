class Solution {
public:
    int minSetSize(vector<int>& arr) {

        unordered_map<int,int> m;
        int i = 0;
        for (auto a : arr) {
            m[a]++;
            i++;
        }

        priority_queue<pair<int,int>> pq;
        for (auto a : m) {
            pq.push(make_pair(a.second, a.first));
        }
        
        int j = 0;
        int result = 0;
        while (j < i / 2) {
            j += pq.top().first;
            pq.pop();
            result++;
        }
        return result;
    }
};
