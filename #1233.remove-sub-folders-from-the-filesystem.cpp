class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        vector<string> results;
        std::sort(folder.begin(), folder.end());
        for (string f: folder) {
            if (results.empty()
                || results.back() != f.substr(0, results.back().length())
                || f[results.back().length()] != '/') {
                results.push_back(f);
            } 
        }
        return results;
    }
};
