class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        int size = words.size();
        vector<string> result;
        for (int i = 0; i < size; i++) {
            map<char, char> pt2word;
            map<char, char> word2pt;
            bool isMatch = true;
            int colSize = words[i].size();
            for(int j = 0; j < colSize; j++){
                if (pt2word.find(pattern[j])==pt2word.end()) {
                    pt2word.insert(make_pair(pattern[j], words[i][j]));
                }

                if (word2pt.find(words[i][j])==word2pt.end()) {
                    word2pt.insert(make_pair(words[i][j], pattern[j]));
                }

                if ((words[i][j] != pt2word[pattern[j]]) || (pattern[j] != word2pt[words[i][j]])) {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch) {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};
