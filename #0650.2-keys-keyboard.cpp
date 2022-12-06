class Solution {
public:
    int minSteps(int n) {

        vector<int> result(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            result[i] = i;
            for (int j = i - 1; j >= 2; j--) {
                if (i % j == 0) {
                    result[i] = result[j] + i / j;
                    break;
                }
            }
        }
        return result[n];
    }
};
