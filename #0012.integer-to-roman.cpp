class Solution {
public:
    string intToRoman(int num) {

        string result;
        auto it = cbegin(vsymbols);
        while (num) {
            if (num >= it->first) {
                num -= it->first;
                result += it->second;
            } else {
                ++it;
            }
        }
        return result;
    }

private:
    vector<pair<int,string>> vsymbols {
        { 1000, "M" }, { 900, "CM" }, { 500, "D" }, { 400, "CD" },
        { 100, "C" }, { 90, "XC" }, { 50, "L" }, { 40, "XL" }, 
        { 10, "X" }, { 9, "IX" }, { 5, "V" }, { 4, "IV" }, 
        { 1, "I" }
    };
};
