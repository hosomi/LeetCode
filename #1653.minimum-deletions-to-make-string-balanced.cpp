class Solution {
public:
    int minimumDeletions(string s) {

        int n = s.size() - 1;
        int index = 0;
        int result = 0;
        for (int i = n; i >= 0; i--) {
            if (s[i] == 'a') {
                index++;
            } else if (s[i] == 'b' && index > 0) {
                index--;
                result++;
            }
        }
        return result;
    }
};
