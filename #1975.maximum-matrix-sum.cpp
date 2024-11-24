class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        long long sum = 0;
        long long xmin = 1e6;
        long long numNag = 0;
        for (auto& v: matrix) {
            for (auto x : v) {
                if (x < 0) {
                    numNag++;
                }
                xmin = std::min<long long>(xmin, abs(x));
                sum += std::abs(x);
            }
        }
        return numNag % 2 == 0 ? sum : sum - xmin * 2;
    }
};
