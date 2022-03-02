class Solution {
public:
    string reverseWords(string s) {

        int size = s.size();
        int index = 0;
        for (int i = 1; i < size; ++i) {
            if (s[i] == ' ') {
                reverse(begin(s) + index, begin(s) + i);
                index = i + 1;
            }
        }

        std::reverse(s.begin() + index, s.end());
        return s;
    }
};
