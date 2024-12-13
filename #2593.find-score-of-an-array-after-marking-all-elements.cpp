class Solution {
public:
    long long findScore(vector<int>& nums) {

        vector<vector<int>> v1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            v1.push_back({nums[i], i});
        }

        std::sort(v1.begin(), v1.end(), [&](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        vector<int> v2(n, 1);
        long long result = 0;
        for (int i = 0; i < n; i++) {
            if (v2[v1[i][1]]) {
                v2[v1[i][1]] = 0;
                result += v1[i][0];
                if (v1[i][1]) {
                    v2[v1[i][1] - 1] = 0;
                }
                if (v1[i][1] < n - 1) {
                    v2[v1[i][1] + 1] = 0;
                }
            }
        }
        return result;
    }
};
