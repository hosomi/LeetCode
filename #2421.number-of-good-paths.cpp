class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        int size = vals.size();
        par.resize(size + 2);
        sz.resize(size + 2, 1);
        
        for (int i = 0; i < size; i++) {
            par[i] = i;
        }
        
        set<int> val;
        for (int i = 0; i < size; i++) {
            val.insert(vals[i]);
        }
        
        map<int,vector<int>> m;
        for (int i = 0; i < edges.size(); i++) {
            m[std::max(vals[edges[i][0]], vals[edges[i][1]])].push_back(i);
        }
        
        int result = size;
        while (val.size()) {
            int v =* val.begin();
            val.erase(v);
            map<int,set<int>> cmp;
            for (auto inedx : m[v]) {
                int i = findParent(edges[inedx][0]);
                int j = findParent(edges[inedx][1]);
                Union(i, j);
            }
            
            for (auto inedx : m[v]) {
                int i = findParent(edges[inedx][0]);
                int j = findParent(edges[inedx][1]);
                if(vals[edges[inedx][0]] == v) {
                    cmp[i].insert(edges[inedx][0]);
                }

                if (vals[edges[inedx][1]] == v) {
                    cmp[j].insert(edges[inedx][1]);
                }
            }
            
            int cur = 0;
            for (auto c : cmp) {
                cur += (c.second.size() * (c.second.size() - 1)) >> 1;
            }
            result += cur;
        }
        return result;
    }

private:
    vector<int> par,sz;

    int findParent(int u){
        if(par[u]==u)
            return u;
        return par[u]=findParent(par[u]);
    }
    
    void Union(int u,int v){
        if(u==v)
            return;
        
        if(sz[u]>sz[v])
            swap(u,v);
        
        par[u]=v;
        sz[v]+=sz[u];
    }
};
