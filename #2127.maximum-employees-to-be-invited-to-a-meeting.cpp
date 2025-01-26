class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {

        int n = favorite.size();
        vector<set<int>> gr(n);
        for (int i = 0; i < n; i++) {
            gr[i].insert(favorite[i]);
        }

        vector<int> deg(n, 0), vis(n, 0);
        for (auto x : gr) {
            for (auto y : x) {
                deg[y]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                vis[i] = 1; q.push(i);
            }
        }

        vector<int> len(n, 0);
        while (!q.empty()) {
            auto z = q.front();
            q.pop();
            for (auto x : gr[z]) {
                deg[x]--;
                if (deg[x] == 0) {
                    q.push(x);
                    vis[x] = 1;
                }

                len[x] = std::max(len[x], 1 + len[z]);
            }
        }

        int ans = 0;
        int ans1 = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int res = 0;
                for (int j = i; vis[j] == false; j = favorite[j]) {
                    vis[j] = 1; res++;
                }

                if (res == 2) {
                    ans1 += 2 + len[i] + len[favorite[i]];
                } else {
                    ans = std::max(ans, res);
                }
            }
        }

        return std::max(ans, ans1);
    }
};
