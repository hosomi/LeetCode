class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
		vector<vector<int>> adjlist(n);
        for (int i=0; i < edges.size(); i++) {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
		
        vector<pair<int, int>> dist(n, {0, 0});
        vector<bool> vis(n, false);
        getdist(dist, adjlist, vis, 0);
        fill(vis.begin(), vis.end(), false);
        assigndist(dist, adjlist, vis, 0, -1);

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = dist[i].first;
        }
        return result;
    }

private:
    pair<int, int> getdist(vector<pair<int, int>>& dist,
        vector<vector<int>>& adjlist,
        vector<bool>& vis, int node) {

        vis[node] = true;
        for (int i = 0; i < adjlist[node].size(); i++) {
            if (vis[adjlist[node][i]]) {
                continue;
            }
            
            pair<int, int> tmp = getdist(dist, adjlist, vis, adjlist[node][i]);
            dist[node].first += tmp.first + tmp.second;
            dist[node].second += tmp.second;
        }

        dist[node].second++;
        return dist[node];
    }
    
    void assigndist(vector<pair<int, int>>& dist,
        vector<vector<int>>& adjlist,
        vector<bool>& vis, int node, int par) {

        vis[node] = true;
        if (par != -1) {
            dist[node].first = dist[par].first+adjlist.size()-2*dist[node].second;
        }
        
        for (int i = 0; i < adjlist[node].size(); i++) {
            if (!vis[adjlist[node][i]]) {
                assigndist(dist, adjlist, vis, adjlist[node][i], node);
            }
        }
        
    }
};
