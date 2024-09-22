class Solution {
public:
    int findKthNumber(int n, int k) {

        auto getGap = [&n](long left, long right) {
            long gap = 0;
            while (left <= n) {
                gap += (std::min)(long(n + 1), right) - left;
                left *= 10;
                right *= 10;
            }
            return gap;
        };

        long currNum = 1;
        for (int i = 1; i < k;) {
            long gap = getGap(currNum, currNum + 1);
            if (i + gap <= k) {
                i += gap;
                ++currNum;
            } else {
                ++i;
                currNum *= 10;
            }
        }
        return currNum;
    }
};
