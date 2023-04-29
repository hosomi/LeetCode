class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

        vector<int>parent(n, -1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int esize = edgeList.size();
        for (int i = 0; i < esize; i++) {
            std::swap(edgeList[i][0],edgeList[i][2]);
        }
        sort(edgeList.begin(), edgeList.end());

        int qsize = queries.size();
        vector<pair<int,int>>second;
        for (int i = 0; i < qsize; i++) {
            second.push_back({queries[i][2],i});
        }
        sort(second.begin(), second.end());

        int j = 0;
        vector<bool>result(qsize, false);
        for (int i = 0; i < qsize; i++) {
            while (j < esize && edgeList[j][0] < second[i].first) {
                int e = edgeList[j][1],v = edgeList[j][2];
                int pe = dsu(parent, e);
                int pv = dsu(parent, v);
                if (pe != pv) {
                    parent[pe] = pv;
                }
                j++;
            }

            int x = queries[second[i].second][0];
            int y = queries[second[i].second][1];
            int px = dsu(parent,x);
            int py = dsu(parent,y);
            if (px == py) {
                result[second[i].second] = true;
            }
        }
        return result;
    }

private:
    int dsu(vector<int>& parent, int x) {
    
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = dsu(parent, parent[x]);
    }
};
