class Solution {
public:
    int lengthOfLastWord(string s) {

        int start = s.length() -1;
        int index = 0;
        for (int i = start; i >= 0; i--) {
            if (s[i] == ' '  && index) {
                break;
            } else if(s[i] !=' ') {
                index++;
            }
        }
        return index;
    }
};
