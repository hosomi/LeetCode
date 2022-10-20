class Solution {
public:
    vector<string> letterCasePermutation(string s) {

        int size = s.size();
        vector<string> result;
        result.push_back(s);
        for (int i = 0; i < size; i++) {
            char c = s[i];
            if (isalpha(c)) {
                vector<string> v;
                for (string r : result) {
                    string tmp(r.begin(), r.end());
                    if (islower(c)) {
                        tmp[i] = toupper(c);
                    } else if(isupper(c)){
                        tmp[i] = tolower(c);
                    }
                    v.push_back(tmp);
                }
                result.insert(result.end(), v.begin(), v.end());
            }
        }
        return result;
    }
};
