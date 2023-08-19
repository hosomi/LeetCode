class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> v(n);
        for (auto &e : edges) {
            int f = e[0];
            int s = e[1];
            int t = e[2];
            v[f].emplace_back(s, t);
            v[s].emplace_back(f, t);
        }

        vector<vector<int>> result(2);
        for (int i = 0; i < edges.size(); i++) {
            auto &e = edges[i];
            int f = e[0];
            int s = e[1];
            int t = e[2];
            int m = minimax(v, f, s);
            if (t < m) {
                result[0].push_back(i);
            } else if (t == m) {
                result[1].push_back(i);
            }
        }
        return result;
    }

private:
    int minimax(vector<vector<pair<int, int>>> &v, int src, int dst) {

        vector<int> dist(v.size(), 1e9);
        priority_queue<pair<int, int>> pq;
        pq.emplace(dist[src] = 0, src);
        while (!pq.empty()) {
            auto [pri, f] = pq.top();
            pq.pop();
            if (-pri > dist[f]) {
                continue;
            }

            for (auto &[s, t] : v[f]) {
                if (f == src && s == dst) {
                    continue;
                }

                if (dist[s] > std::max(dist[f], t)) {
                    dist[s] = std::max(dist[f], t);
                    pq.emplace(-dist[s], s);
                }
            }
        }
        return dist[dst];
    }
};
