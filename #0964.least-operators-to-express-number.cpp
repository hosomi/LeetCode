class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {

        if (x == target) {
            return 0;
        }
        
        if (x > target) {
            return std::min(2 * target - 1, 2 * (x - target));
        }
        
        long long cur = x;
        int count = 0;
        while (cur < target) {
            cur *= x;
            ++count;
        }

        if (cur == target) {
            return count;
        }

        int sub = INT_MAX;
        int add = INT_MAX;
        if(cur - target < target){
            sub = count + leastOpsExpressTarget(x, cur - target);
        }

        add = count - 1 + leastOpsExpressTarget(x, target-cur / x);
        return min(sub, add) + 1;
    }
};
