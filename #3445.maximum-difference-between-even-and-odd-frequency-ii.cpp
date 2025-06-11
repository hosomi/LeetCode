class Solution {
public:
    int maxDifference(string s, int k) {

        int n = s.size();
        int ans = INT_MIN;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == j) continue;
                int c1[n + 1], c2[n + 1];
                c1[0] = 0, c2[0] = 0;
                for (int kk = 0; kk < n; kk++) {
                    int cur = s[kk] - '0';
                    c1[kk + 1] = c1[kk], c2[kk + 1] = c2[kk];
                    if (cur == i) {
                        c1[kk + 1]++;
                    }
                    if (cur == j) {
                        c2[kk + 1]++;
                    }
                }

                int mn[4];
                for (int i = 0; i < 4; i++) {
                    mn[i] = INT_MAX;
                }

                int idx[4];
                memset(idx, -1, sizeof(idx));

                mn[0] = 0;
                idx[0] = 0;
                for (int kk = k; kk <= n; kk++) {
                    int cur1 = c1[kk], cur2 = c2[kk];
                    int p1 = cur1 & 1, p2 = cur2 & 1;
                    int cari = ((p1 ^ 1) << 1) + p2;
                    if (mn[cari] != INT_MAX) {
                        if (c2[idx[cari]] != cur2) {
                            ans = max(ans, (cur1 - cur2) - mn[cari]);
                        }
                    }
                    p1 = c1[kk - k + 1] & 1;
                    p2 = c2[kk - k + 1] & 1;
                    int nw = c1[kk - k + 1] - c2[kk - k + 1];
                    int id = (p1 << 1) + p2;
                    if (nw < mn[id]) {
                        mn[id] = nw;
                        idx[id] = kk - k + 1;
                    }
                }
            }
        }
        return ans;
    }
};
