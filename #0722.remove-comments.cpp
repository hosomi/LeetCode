class Solution {
public:
    vector<string> removeComments(vector<string>& source) {

        string s;
        for (auto& line : source) {
            s += line+'\n';
        }

        vector<string> result;
        for (stringstream ss(regex_replace(s,
            regex("//.*|/\\*(.|\n)*?\\*/"),""));
            std::getline(ss,s);) {

            if (!s.empty()) {
                result.push_back(s);
            }
        }
        return result;
    }
};
