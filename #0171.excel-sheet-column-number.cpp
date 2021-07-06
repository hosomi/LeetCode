class Solution {
public:
    int titleToNumber(string columnTitle) {

        int num = 0;
        for (const char& c : columnTitle) {
            num *= 26;
            num += c - 'A' + 1;
        }
        return num;
    }
};
