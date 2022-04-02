class Solution {
public:
    bool validPalindrome(string s) {

        int size = s.size();
        for (int i = 0; i < size / 2; i++) {
            int j = size -1 - i;
            if (s[i] != s[j]) {
                return isPalindromeRange(s, i + 1, j) || 
                    isPalindromeRange(s, i, j - 1);
            }
        }
        return true;
    }

private:
    
    bool isPalindromeRange(string s, int i, int j) {

        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};
