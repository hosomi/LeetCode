class Solution {
public:
    void reverseString(vector<char>& s) {

        int i = 0;
        int index = s.size() - 1;
        while (i < index) {
            std::swap(s[i++], s[index--]);
        }
    }
};
