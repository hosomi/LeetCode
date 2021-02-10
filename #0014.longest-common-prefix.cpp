class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) {
            return string();
        }

        string result = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int size = min(result.size(), strs[i].size());
            int index = 0;
            for (;index < size; index++) {
                if (result[index] != strs[i][index]) {
                    break;
                }
            }
            result = strs[i].substr(0, index);
        } 
        return result;
    }
};
