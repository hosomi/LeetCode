class Solution {
public:
    string simplifyPath(string path) {

        vector<string> v;
        int start = 1;
        string work;
        for (int i = 1; i <= path.length(); ++i) {
            if (i == path.length() || path[i] == '/') {
                work = path.substr(start, i - start);
                if (work == "/") {
                    continue;
                }
                if (work == "..") {
                    if (!v.empty()) v.pop_back();
                } else if (work.length() > 0 && work != ".") {
                    v.push_back(std::move(work));
                }
                start = i + 1;
            }
        }

        string result;
        for (int i = 0; i < v.size(); ++i) {
            result += "/" + v[i];  
        }
        return result.empty() ? "/" : result;
    }
};
