class Solution {
public:
    int climbStairs(int n) {
    
        int result = 1;
        int last = 1;
        for (int i = 2; i <= n; i++) {
            last += result;
            swap(result, last);
        }
        return result;
    }
};
