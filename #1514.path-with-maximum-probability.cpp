class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        int size = edges.size();
        unordered_map<int, list<pair<int,double>>> adj;
        for (int i = 0; i < size; i++)   {
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<double> prob(n, 0);
        queue<pair<double,int>> q;
        prob[start] = 1;
        q.push({1, start});
        while (!q.empty()) {
            auto it = q.front();
            double p1 = it.first;
            int node = it.second;
            q.pop();

            for (auto it : adj[node]) {
                double p2 = it.second;
                int cnode = it.first;
                double ch = p1 * p2;
                if (ch > prob[cnode]) {
                    prob[cnode] = ch;
                    q.push({ch,cnode});
                }
            }
        }
        return prob[end];
    }
};
