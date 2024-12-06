class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        int result = 0;
        unordered_set<int> s(begin(banned), end(banned));
        for (int i = 1; i <= n; ++i) {
            if (s.find(i) == s.end()
                && maxSum - i >= 0) {
                    result++;
                    maxSum -= i;
            }
        }
        return result;
    }
};
