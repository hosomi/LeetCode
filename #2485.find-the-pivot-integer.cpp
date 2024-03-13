class Solution {
public:
    int pivotInteger(int n) {

        int left;
        int right;
        left = right = 0;
        for (int i = 1; i <= n; i++) {
            left += i;
        }

        for (int i = n; i > 0; i--) {
            right += i;
            if (left == right) {
                return i;
            }
            left -= i;
        }
        return -1;
    }
};
