class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int size1 = word1.length();
        int size2 = word2.length();
        string result = "";
        for (int i = 0; i < size1 || i < size2; i++) {
            if (i < size1) {
                result += word1[i];
            }

            if (i < size2) {
                result += word2[i];
            }
        }
        return result;
    }
};
