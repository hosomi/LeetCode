class Solution {
public:
    string simplifyPath(string path) {

        string result;
        string work;
        vector<string> v;
        stringstream ss(path);
        while(std::getline(ss, work, '/')) {
            if (work == "" or work == ".") {
                continue;
            }

            if (work == ".." and !v.empty()) {
                v.pop_back();
            } else if (work != "..") {
                v.push_back(work);
            }
        }

        for (auto s : v) {
            result += "/" + s;
        }
        return result.empty() ? "/" : result;
    }
};
