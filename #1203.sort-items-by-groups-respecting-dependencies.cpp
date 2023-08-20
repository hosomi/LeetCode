class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        vector<vector<int>> v1(n + 2*m);
        for (int i = 0; i < n; i++) {
            for (auto bt : beforeItems[i]) {
                if (group[i] == group[bt] && group[i] != -1) {
                    v1[bt].push_back(i);
                }
            }
        }

        vector<vector<int>> v2(m);
        for (int i = 0; i < n; i++) {
            if (group[i] != -1) {
                v2[group[i]].push_back(i);
            }
        }

        for (int i = 0; i < m; i++) {
            if (!v2[i].empty()) {
                for (auto it : v2[i]) {
                    v1[n + i].push_back(it);
                    v1[it].push_back(n + m + i);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (auto it : beforeItems[i]) {
                if (group[i] != group[it]) {
                    if (group[i] != -1 && group[it] != -1) {
                        v1[m + n + group[it]].push_back(n + group[i]);
                    } else if (group[it] == -1) {
                        v1[it].push_back(n + group[i]);
                    } else if (group[i] == -1) {
                        v1[m + n + group[it]].push_back(i);
                    }
                }
            }
        }

        vector<int> v3(n + 2*m, 0);
        for (int i = 0; i < n + 2 * m; i++) {
            for (auto it : v1[i]) {
                v3[it]++;
            }
        }

        stack<int> q;
        vector<int> result;
        for (int i = 0; i < n + 2 * m; i++) {
            if (v3[i] == 0) {
                result.push_back(i);
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.top();
            q.pop();
            for (auto it : v1[node]) {
                v3[it]--;
                if (v3[it] == 0) {
                    result.push_back(it);
                    q.push(it);
                }
            }
        }

        vector<int> v4;
        for (auto it : result) {
            if(it < n) {
                v4.push_back(it);
            }
        }

        if (v4.size() == n) {
            return v4;
        } 
        return {};
    }
};
