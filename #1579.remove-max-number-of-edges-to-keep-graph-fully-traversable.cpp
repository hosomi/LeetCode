class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        vector<int> a(n + 1);
        vector<int> b(n + 1);
        int compa;
        int compb;
        compa = n;
        compb = n;
        int edg = 0;
        for (int i = 0; i <= n; i++) {
            a[i] = b[i] = i;
        }

        for (auto i : edges) {
            if (i[0] == 3) {
                edg += Union(i[1], i[2], a, compa)
                | Union(i[1], i[2], b, compb);
            }
        }

        for (auto i : edges) {
            if (i[0] == 1) {
                edg += Union(i[1], i[2], a, compa);
            } else if(i[0] == 2) {
                edg += Union(i[1], i[2], b, compb);
            }
        }

        if (compa == 1 && compb == 1) {
            return edges.size() - edg;
        }
        return -1;
    }

private:
    int findP(int u,vector<int>& p) {

        if (p[u] == u) {
            return u;
        }

        return p[u] = findP(p[u],p);
    }

    bool Union(int a,int b,vector<int> &v,int &comp) {

        a = findP(a, v);
        b = findP(b, v);
        if (a == b) {
            return 0;
        }

        v[a] = b;
        comp--;
        return 1;
    }
};
