class Solution {
public:
    int climbStairs(int n) {

        int step = 1;
        int last = 1;
        for (int i = 2; i <= n; i++) {
            last += step;
            swap(step, last);
        }

        return step;
    }
};
