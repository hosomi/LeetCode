class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) {
            return {};
        }
        
        vector<vector<char>> alpha(10);
        alpha[0] = {' '};
        alpha[1] = {};
        alpha[2] = {'a','b','c'};
        alpha[3] = {'d','e','f'};
        alpha[4] = {'g','h','i'};
        alpha[5] = {'j','k','l'};
        alpha[6] = {'m','n','o'};
        alpha[7] = {'p','q','r','s'};
        alpha[8] = {'t','u','v'};
        alpha[9] = {'w','x','y','z'};

        vector<string> v;
        vector<string> result{""};
        for (char digit : digits) {
            v = {};
            for (const string& s : result) {
                for (char c : alpha[digit - '0']) {
                    v.push_back(s + c);
                }
            }
            result.swap(v);
        }
        return result;
    }
};
