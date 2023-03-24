class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<pair<int, int>> vp[n];
        for(auto x: connections){
            vp[x[0]].push_back({x[1], 1});
            vp[x[1]].push_back({x[0], 0});
        }

        vector<int> vis(n, 0);
        int count = 0;         
        dfs(0, vis, vp, count);     
        return count;
    }

private:
    void dfs(int index, vector<int> &vis,
        vector<pair<int, int>>vp[], int &count) {

        vis[index] = 1;
        for (auto x: vp[index]) {
            if (!vis[x.first]) {
                if (x.second == 1) {
                    count++;
                }
                dfs(x.first, vis, vp, count);
            }
        }
        
    }
};
