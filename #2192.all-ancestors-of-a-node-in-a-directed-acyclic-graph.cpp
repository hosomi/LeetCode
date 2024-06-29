class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<int>v[n];
        for (vector<int> it : edges) {
            v[it[0]].push_back(it[1]);
        }
        
        vector<vector<int>>vec(n);
        for (int i = 0; i < n; i++) {
            dfs(v, i, i, vec);
        }
        return vec;
    }

private:
    void dfs(vector<int>v[], int &i, int parent,
        vector<vector<int>> &vec) {

        for (int idx = 0; idx < v[parent].size(); idx++) {
           int child = v[parent][idx];
           if (!vec[child].size() || vec[child].back() != i) {
               vec[child].push_back(i);
               dfs(v, i, child, vec);
           }
       }
   }
};
