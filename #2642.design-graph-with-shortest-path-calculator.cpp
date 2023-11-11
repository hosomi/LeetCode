class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {

        _n = n;
        v.resize(_n);
        for (auto&e : edges){
            v[e[0]].push_back({e[1], e[2]});
        }
    }
    
    void addEdge(vector<int> edge) {

        v[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {

        vector<int> d(_n, 1e9);
        d[node1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, node1});
        while (pq.size()) {
            auto [du,u] = pq.top();
            pq.pop();
            if (du != d[u]) {
                continue;
            }

            for (auto&[v, w] : v[u]) {
                if (du + w < d[v]) {
                    d[v] = du+w;
                    pq.push({d[v], v});
                }
            }
        }

        return d[node2] != 1e9 ? d[node2] : -1;
    }

private:
    int _n;
    vector<vector<pair<int,int>>> v;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
