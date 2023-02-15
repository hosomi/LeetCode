class Solution {
public:
    vector<int> constructArray(int n, int k) {
        
        vector<int> result(n);
        for (int i = 0, j = 1, l = k + 1; i <= k; i++) {
            result[i] = i % 2 ? l-- : j++;
        }

        for (int i = k + 1; i < n; i++) {
            result[i] = i + 1;
        }
        return result;
    }
};
