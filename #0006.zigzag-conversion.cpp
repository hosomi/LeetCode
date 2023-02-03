class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1) {
            return s;
        }

        vector<string> v(numRows,"");
        int work = -1;
        int index = 0;
        for (char ch : s) {
            if (index == 0 || index == numRows - 1) {
                work *= -1;
            }
            v[index].push_back(ch); 
            index += work;
        }

        string result;
        for (int i = 0; i < numRows; ++i) {
            result += v[i]; 
        }
        return result;
    }
};
