class Solution {
public:
    bool isPerfectSquare(int num) {

        long long n = num;
        while (n * n > num) {
            n = (n + num / n) >> 1;
        }
        return n*n == num;
    }
};
