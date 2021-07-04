class Solution {
public:
    string convertToTitle(int columnNumber) {

        string result; 
        while (columnNumber) {
            result.insert(result.begin(), 'A' + (columnNumber - 1) % 26);
            columnNumber = (columnNumber - 1) / 26;
        }
        return result;
    }
};
