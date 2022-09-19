class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {

        unordered_map<string, unordered_set<string>> um;
        for (const string& path: paths) {
            std::istringstream iss(path);
            vector<string> files{istream_iterator<string>{iss},
                 std::istream_iterator<string>{}};
            for (int i = 1; i < files.size(); i++) {
                int openParentheses = files[i].find('(');
                string fileName = files[i].substr(0, openParentheses),
                    fileContents = files[i].substr(openParentheses + 1,
                       files[i].size() - 1 - openParentheses - 1);
                um[fileContents].insert(files[0] + "/" + fileName);
            }
        }
        
        vector<vector<string>> result;
        for (auto &[ignore, group]: um) {
            if (group.size() > 1) {
                result.push_back({begin(group), end(group)});
            }
        }
        return result;
    }
};
