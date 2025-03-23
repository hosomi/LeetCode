class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        int mod = (int)1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> count(n, 0); 
        dist[0] = 0;
        count[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            long long cost = ele.first; 
            int node = ele.second;
            for (auto it : adj[node]) {
                if (cost + it.second < dist[it.first]) {
                    count[it.first] = count[node];
                    dist[it.first] = cost + it.second;
                    pq.push({dist[it.first], it.first});
                } else if (cost + it.second == dist[it.first]) {
                    count[it.first] = (count[it.first] + count[node]) % mod;
                }
            }
        }
        return count[n - 1] % mod;
    }
};
