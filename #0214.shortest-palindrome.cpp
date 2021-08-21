class Solution {
public:
    string shortestPalindrome(string s) {

        int size = s.size();
        int index = 0;
        for(int i = size - 1; i >= 0; --i) {
            if (s[index] == s[i]) {
                ++index;
            }
        }

        if (index == size) {
            return s;
        }

        string target = s.substr(index);
        string temp = target;
        reverse(temp.begin(), temp.end());
        return temp + shortestPalindrome(s.substr(0, index)) + target;
    }
};
