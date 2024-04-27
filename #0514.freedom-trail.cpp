class Solution {
public:
    int findRotateSteps(string ring, string key) {

        n = key.length();
        n2 = ring.length();
        for (int i = 0; i < ring.length();i++) {
            m[ring[i]].push_back(i);
        }
        return findRotateSteps(0, 0, key);
    }

private:
    int n;
    int n2;
    map<char, vector<int>>m;
    map<pair<int, int>,int>dp;

    int findRotateSteps(int top, int i, string &key) {

        if (i == n) {
            return 0;
        }

        if (dp.count({top, i}) > 0) {
            return dp[{top, i}];
        }

        int result = INT_MAX;
        for (auto ind : m[key[i]]) {
            result = std::min(result,
                1 + std::min(std::abs(ind - top),
                    n2 - std::abs(ind - top))
                + findRotateSteps(ind, i + 1, key));
        }
        return dp[{top, i}] = result;
    }
};
