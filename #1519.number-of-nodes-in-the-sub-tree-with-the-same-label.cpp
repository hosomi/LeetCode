class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<vector<int>> v(n);
        vector<vector<int>> counter(n, vector<int>(26, -1));
        for (vector<int>& edge : edges) {
            v[edge[0]].push_back(edge[1]);
            v[edge[1]].push_back(edge[0]);
        }
        
        vector<int> result(n);
        vector<bool> visited(n, false);
        visited[0] = true;
        countSubTrees(v, labels, visited, 0, result);
        return result;
    }

private:
    vector<int> countSubTrees(vector<vector<int>>& v, string& labels,
        vector<bool>& visited, int cur, vector<int>& result) {

        vector<int> counter(26, 0);
        counter[labels[cur] - 'a'] = 1;
        for (int i : v[cur]) {
            if (!visited[i]) {
                visited[i] = true;
                vector<int> subcounter = 
                    countSubTrees(v, labels, visited, i, result);

                for (int j = 0; j < counter.size(); ++j) {
                    counter[j] += subcounter[j];
                }
            }
        }
        result[cur] += counter[labels[cur] - 'a'];
        return counter;
    };
};
