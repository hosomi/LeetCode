class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int cur = 0;
        int n = A.size();
        vector<int> ans(n);
        vector<int> seen(n + 1);
        for (int i = 0; i < n; ++i) {
            if (++seen[A[i]] == 2) {
                cur++;
            }

            if (++seen[B[i]] == 2) {
                cur++;
            }
            ans[i] = cur;
        }
        return ans;
    }
};
