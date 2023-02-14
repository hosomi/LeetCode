class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        
        int i;
        int j;
        int size = strs.size();
        int par[size + 1];
        int rnk[size + 1];
        for (i = 0; i < size; i++) {
            par[i] = i;
            rnk[i] = 1;
            for (j = i + 1; j < size; j++) {
                if (satisfy(strs[i], strs[j])) {
                    edges.push_back({i, j});
                }
            }
        }

        par[size] = size;
        rnk[size] = 1;
        
        for (auto p : edges) {
            int u = find(par, p.first);
            int v = find(par, p.second);
            if (u != v) {
                if (rnk[u] < rnk[v]) {
                    swap(u, v);
                }
                rnk[u] += rnk[v];
                par[v] = u;
            }
        }
        
        int cnt = 0;
        for (i = 0; i < size; i++) {
            if (i == par[i]) {
                cnt++;
            }
        }
        return cnt;
    }

private:
    vector<pair<int, int>> edges;

    bool satisfy(string S, string T) {

        if (S.length() != T.length()) {
            return 0;
        }
        
        int i;
        int l = S.length();
        int f = -1;
        int s = -1;
        int cnt = 0;
        for (i = 0; i < l; i++) {
            if (S[i] != T[i]) {
                cnt++;
                if (cnt>2) {
                    return 0;
                }

                if (f == -1) {
                    f = i;
                } else {
                    s = i;
                }                    
            }
        }
        
        if (cnt == 0) {
            return 1;
        }
        
        if (cnt != 2) {
            return 0;
        }
        
        if (S[f] == T[s] && S[s] == T[f]) {
            return 1;
        }
        return 0;
    }
    
    int find(int par[], int u) {

        if (u == par[u]) {
            return u;
        }
        return par[u] = find(par, par[u]);
    }
};
