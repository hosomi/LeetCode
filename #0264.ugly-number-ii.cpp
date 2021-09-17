class Solution {
public:
    int nthUglyNumber(int n) {

        if (n <= 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        vector<int> result(n);
        int ugly1 = 0;
        int ugly2 = 0;
        int ugly3 = 0;
        result[0] = 1;
        for (int i = 1; i < n; ++i){
            result[i] = std::min({
                result[ugly1] * 2,
                result[ugly2] * 3,
                result[ugly3] * 5});

            if (result[i] == result[ugly1]*2) {
                ++ugly1;
            }
            
            if (result[i] == result[ugly2]*3) {
                ++ugly2;
            }

            if (result[i] == result[ugly3]*5) {
                ++ugly3;
            }
        }
        return result[n - 1];
    }
};
