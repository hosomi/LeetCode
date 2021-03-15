class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;
        unordered_map<string, vector<int>> m;
        int size = strs.size();
        string s;
        for (int i = 0; i < size; ++i) {
            s = strs[i];
            sort(begin(s), end(s));
            m[s].push_back(i);
        }

        for (const auto& v : m) {
            result.push_back({});
            for (int i : v.second) {
                result.back().push_back(strs[i]);
            }
        }

        return result;
    }
};
