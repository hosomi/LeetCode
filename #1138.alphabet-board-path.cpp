class Solution {
public:
    string alphabetBoardPath(string target) {
        
        string result = "";
        int currRow = 0;
        int currCol = 0;
        int letterRow;
        int letterCol;
        int ascii;
        for (int i = 0; i <target.length(); i++) {
            ascii=int(target[i]);
            letterRow=(ascii-97)/5;
            letterCol=(ascii-97)%5;
            if (letterRow > currRow) {
                for (int i = 1; i <= letterRow - currRow; i++) {
                    result.push_back('D');
                }
            } else if (letterRow < currRow) {
                for (int i = 1; i <= currRow - letterRow; i++) {
                    result.push_back('U');
                }
            }

            if (letterCol > currCol) {
                for (int i = 1; i <= letterCol - currCol; i++) {
                    result.push_back('R');
                }
            } else if (letterCol < currCol) {
                if (target[i] == 'z') {
                    result.pop_back();
                }

                for (int i = 1; i <= currCol - letterCol; i++) {
                    result.push_back('L');
                }

                if (target[i] == 'z') {
                    result.push_back('D');
                }
            }
            
            result.push_back('!');
            currCol = letterCol;
            currRow = letterRow;
        }
        return result;
    }
};
