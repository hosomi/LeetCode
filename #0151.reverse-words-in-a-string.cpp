class Solution {
public:
    string reverseWords(string s) {

        std::istringstream is(s);
        string work;
        is >> s;
        while (is >> work) {
            s = work + " " + s;
        }
        return s;
    }
};
