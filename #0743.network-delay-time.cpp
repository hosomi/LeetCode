class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto edge : times) {
            graph[edge[0]].push_back(make_pair(edge[2], edge[1]));            
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push(make_pair(0, k));        
        while (!pq.empty()) {
            pair<int,int> x = pq.top();
            pq.pop();
            for (auto g : graph[x.second]) {
                int d = dist[x.second] + g.first;
                if (d < dist[g.second]) {
                    dist[g.second] = d;
                    pq.push(make_pair(d, g.second));
                }
            }            
        }       

        int size = dist.size();
        int max_time = INT_MIN;
        for (int i = 1; i < size; ++i) {
            if (max_time < dist[i]) {
                max_time = dist[i];
            }
        }
        
        return max_time == INT_MAX ? - 1 : max_time;
    }
};
