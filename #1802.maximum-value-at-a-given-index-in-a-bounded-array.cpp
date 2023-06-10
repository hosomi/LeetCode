class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        
        long long l = 1;
        long long i;
        long long h = maxSum + 10;
        long long result = 1;
        while (l <= h) {
            long long curr=0;
            long long m = l + (h - l) / 2;
            curr = m > index ?
                (m * (m + 1) - (m - index) * (m - index - 1)) / 2
                : ((m * (m + 1)) / 2 + (index - m + 1));

            curr -= m;
            long long tindex = n - index - 1;
            curr += m > tindex ?
                (m * (m + 1) - (m - tindex) * (m - tindex - 1)) / 2
                : ((m * (m + 1)) / 2 + (tindex - m + 1));

            if (curr <= maxSum) {
                l = m + 1;
                result = std::max(result, m);
            } else {
                h = m - 1;
            }
        }
        return result;
    }
};
