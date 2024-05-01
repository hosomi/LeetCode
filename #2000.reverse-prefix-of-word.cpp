class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int i = 0;
        while (word[i] != ch && i < word.size()) {
            i++;
        }

        i++;
        if (i <= word.size()) {
            reverse(word.begin(), word.begin() + i);
        }
        return word;
    }
};
