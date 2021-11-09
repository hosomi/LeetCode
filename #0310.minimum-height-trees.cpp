class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<int> tree[n];
        vector<int> edge(n, 0);
        for (auto e:edges) {
            tree[e[1]].push_back(e[0]);
            tree[e[0]].push_back(e[1]);
            edge[e[0]]++;
            edge[e[1]]++;
        }

        int index = n;
        while (index > 2) {
            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (edge[i] == 1) {
                    q.push(i);
                    edge[i] = -1;
                    index--;
                }
            }
            while (!q.empty()) {
                int f = q.front();
                q.pop();
                for (int g : tree[f]) {
                    edge[g]--;
                }
            }
        }

        vector<int> result;
        for (int i = 0;i < n; i++) {
            if (edge[i] == 0 || edge[i] == 1) {
                result.push_back(i);
            }
        }
        return result;
    }
};
