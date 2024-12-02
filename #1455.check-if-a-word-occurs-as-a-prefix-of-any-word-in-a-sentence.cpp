class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int n = searchWord.size();
        stringstream ss(sentence);
        string word;
        bool isfound = false;
        int result = 1;
        while (ss >> word) {
            if (word.substr(0, n) == searchWord) {
                isfound = true;
                break;
            }
            result++;
        }
        return isfound ? result : -1;
    }
};
