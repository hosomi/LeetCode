class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {

        std::sort(words.begin(), words.end(), [](string s1, string s2) {
            return s1.size() > s2.size();
        });

        int size = words.size();
        string str;
        for (int i = 0;i < size; i++) {
            string s = words[i]+'#';
            if (str.find(s) == -1) {
                str += (words[i] + '#');
            }
        }
        return str.size();
    }
};
