class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        std::sort(items.begin(), items.end());

        int m = items.size();
        int n = queries.size();
        for (int i = 1; i < m; i++) {
            if (items[i][1] < items[i - 1][1]) {
                items[i][1] = items[i - 1][1];
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int left = 0, right = m;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (items[mid][0] <= queries[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left > 0) {
                res[i] = items[left - 1][1];
            }
        }
        return res;
    }
};
