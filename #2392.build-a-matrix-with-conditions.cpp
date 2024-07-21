class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> row = buildMatrix(rowConditions, k);
        if (row.size() == 0) {
            return {};
        }
        
        vector<int> col = buildMatrix(colConditions, k);
        if (col.size() == 0) {
            return {};
        }
        
        vector<vector<int>> results(k, vector<int>(k));
        for (int i = 1; i <= k; i++) {
            results[row[i] - 1][col[i] - 1] = i;
        }
        
        return results;
    }

private:
    vector<int> buildMatrix(vector<vector<int>> &conditions, int k) {

        vector<int> adj[k + 1];
        vector<int> indegree(k + 1);
        queue<int> q;
        int index = 1;
        for (auto &c: conditions) {
            indegree[c[1]]++;
            adj[c[0]].push_back(c[1]);
        }
        
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> results(k + 1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            results[u] = index;
            index++;
            
            for (auto v: adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (index < k) {
            return {};
        } 
        return results;
    }
};
