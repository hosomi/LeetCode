class Solution {
public:
    int bulbSwitch(int n) {

        if (n == 1) {
            return 1;
        }

        int result = 1;
        while (result * result <= n) {
            result++;
        }
        return result - 1;
    }
};
