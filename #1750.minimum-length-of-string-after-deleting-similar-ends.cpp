class Solution {
public:
    int minimumLength(string s) {

        int i = 0 ;
        int j = s.size() - 1;
        while (i < j){
            if (s[i] != s[j]) {
                return j - i + 1;
            }

            while (i <= j && s[i+1] == s[i]) {
                i++;
            }
            while (j >= i && s[j-1] == s[j]) {
                j--;
            }
            i++;
            j--;
        }
        
        if (j - i + 1  < 0) {
            return 0;
        }
        return j - i + 1;
    }
};
