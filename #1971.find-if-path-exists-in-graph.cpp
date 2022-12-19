class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> v(n);
        for(vector<int> e : edges){
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);
        }

        stack<int> s;
        s.push(source);
        vector<int> v2(n,0);
        while (!s.empty()) {
            int node = s.top();
            s.pop();
            if (node == destination) {
                return true;
            }

            if (v2[node] == 1) {
                continue;
            }

            v2[node] = 1;
            for (int i: v[node]) {
                s.push(i);
            }
        }
        return false;
    }
};
