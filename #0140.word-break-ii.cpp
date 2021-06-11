class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        int size = s.size();
        vector<vector<string>> result(size);
        int start = size -1;
        for (int i = start; i >= 0; --i) {
            if (std::find(wordDict.begin(), wordDict.end(), s.substr(i)) != wordDict.end()) {
                result[i].push_back(s.substr(i));
            }
 
            for (int j = start; j >= i + 1; --j) {
                if (std::find(wordDict.begin(), wordDict.end(), s.substr(i, j-i)) != wordDict.end()
                   && !result[j].empty()) {
                    for (string& work : result[j]) {
                        result[i].push_back(s.substr(i, j-i) + " " + work);
                    }
                }
            }
        }
        return result[0];
    }
};
