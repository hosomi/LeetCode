class Solution {
public:
    int countPrimes(int n) {

        vector<int> v(n, 1);
        int result = 0;
        for (int i = 2; i < n; ++i) {
            if (v[i]) {
                result += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        v[j] = 0;
                    }
                }
            }
        }
        return result;
    }
};
