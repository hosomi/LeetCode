class Solution {
public:
    bool isCircularSentence(string sentence) {

        char last = sentence.back();
        stringstream ss(sentence);
        string str;
        while (ss >> str) {
            if (str[0] != last) {
                return false;
            }
            last = str.back();
        }
        return true;
    }
};
