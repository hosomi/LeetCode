class Solution {
public:
    int numSteps(string s) {

        int i = s.size() - 1;
        while (s[i] == '0') {
            i--;
        }

        int result = s.size() - i - 1;
        while (i > 0) {
            result++;
            int j = i;
            while (--i != -1 && s[i] == '1');
            result += j - i;
        }  
        return result;
    }
};
