class Solution {
public:
    string largestOddNumber(string num) {
        
        int size = num.size(); 
        for (int i = size - 1; i >= 0; i--) {
            if ((num[i]-'0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
