class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {

        vector<array<int, 26>> v(1);
        vector<int> cnt(1);
        int n = 1;
        for (auto x : words) {
            int u = 0;
            for (char ch : x) {
                if (!v[u][ch - 'a']) {
                    v[u][ch - 'a'] = n++;
                    v.push_back({});
                    cnt.push_back(0);
                }
                u = v[u][ch - 'a'];
                ++cnt[u];
            }
        }

        vector<int> results;
        for (auto x : words) {
            int u = 0;
            int cur = 0;
            for (char ch : x) {
                u = v[u][ch-'a'];
                cur += cnt[u];
            }
            results.push_back(cur);
        }
        return results;
    }
};
