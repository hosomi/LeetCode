class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {

        vector<vector<int>> mp(n + 1);
        for (auto& edge : edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n + 1, 0);
        vector<vector<int>> groups;
        vector<int> all_res(n + 1, 0);
        int res = 0;
        int group_cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int first = 1- vis[i];
            if (first) {
                groups.push_back(vector<int>());
            }
            int sub_res = 0;
            vector<int> mark(n + 1, 0);
            queue<int> qe;
            qe.push(i);
            mark[i] = 1;
            while (!qe.empty()) {
                int cur = qe.front();
                qe.pop();
                vis[cur] = 1;
                if (first) {
                    groups[groups.size() - 1].push_back(cur);
                }
                sub_res = max(sub_res, mark[cur]);
                for (int next : mp[cur]) {
                    if (mark[next]) {
                        if (abs(mark[next] - mark[cur]) != 1) return -1;
                        continue;
                    }
                    qe.push(next);
                    mark[next] = mark[cur] + 1;
                }
            }
            all_res[i] = sub_res;
        }

        for (auto group: groups) {
            int sub_res = 0;
            for (int k : group) {
                sub_res = max(sub_res, all_res[k]);
            }
            res += sub_res;
        }
        return res;
    }
};
