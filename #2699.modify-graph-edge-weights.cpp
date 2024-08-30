class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {

        vector<vector<int>> v;
        vector<vector<int>> results;
        vector<vector<int>> results1;
        vector<pair<int, int>> adj[n];
        vector<pair<int, int>> adj1[n];
        for (auto it : edges) {
            if (it[2] == -1) {
                v.push_back({it[0], it[1]});
                adj1[it[0]].push_back({it[1], 1});
                adj1[it[1]].push_back({it[0], 1});
            } else {
                results1.push_back({it[0], it[1], it[2]});
                adj[it[0]].push_back({it[1], it[2]});
                adj[it[1]].push_back({it[0], it[2]});
                adj1[it[0]].push_back({it[1], it[2]});
                adj1[it[1]].push_back({it[0], it[2]});
            }
        }

        auto f = [&](vector<pair<int, int>>ad[], int s, int d)->int {
            vector<int> dis(n, 1e9);
            priority_queue<pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>>> q
            ;
            q.push({0, s});
            dis[s] = 0;
            while (!q.empty()) {
                int ind = q.top().second;
                int wt = q.top().first;
                q.pop();
                for (auto it : ad[ind]) {
                    if (dis[it.first] > wt + it.second) {
                        dis[it.first] = wt + it.second;
                        q.push({dis[it.first], it.first});
                    }
                }
            }
            return dis[d];
        };

        int cnt1 = f(adj, source, destination);
        int cnt2 = f(adj1, source, destination);
        if (cnt1 < target || (cnt2 > target && cnt2 != 1e9)) {
            return results;
        }

        if (v.empty()) {
            if (cnt1 == target) {
                return edges;
            }
        }

        auto ff = [&](int pos, vector<pair<int, int>> a[],
        vector<vector<int>>&v)->int {
            vector<pair<int, int>> aa[n];
            for(auto it : edges) {
                if(it[2]!=-1){
                    aa[it[0]].push_back({it[1], it[2]});
                    aa[it[1]].push_back({it[0], it[2]});
                }
            }

            for (int i = 0; i < pos + 1; i++) {
                aa[v[i][0]].push_back({v[i][1], 1});
                aa[v[i][1]].push_back({v[i][0], 1});
            }

            int num = f(aa, source, destination);
            return num;
        };

        int st = 0;
        int en = v.size() - 1;
        while (st <= en) {
            int mid = st + (en - st) / 2;
            int val = ff(mid, adj, v);
            if (val <= target) {
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        int len = ff(st, adj, v);
        int maxi = 2e9;
        for (int i = 0; i < st; i++) {
            results1.push_back({v[i][0], v[i][1], 1});
        }

        results1.push_back({v[st][0], v[st][1], target - len + 1});
        for (int i = st + 1; i < v.size(); i++) {
            results1.push_back({v[i][0], v[i][1], maxi});
        }
        return results1;
    }
};
