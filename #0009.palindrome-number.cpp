class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }

        long result = 0;
        int palindrome = x;
        while (palindrome > 0) {
            result = result * 10 + palindrome % 10;
            palindrome /= 10;
        }
        return result == x;
    }
};
