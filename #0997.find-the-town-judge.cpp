class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> indegrees(n + 1);
        vector<int> outdegrees(n + 1);
        for (auto a : trust) {
            ++outdegrees[a[0]];
            ++indegrees[a[1]];
        }
        for (int i = 1; i <= n; ++i) {
            if (indegrees[i] == n - 1 && outdegrees[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
