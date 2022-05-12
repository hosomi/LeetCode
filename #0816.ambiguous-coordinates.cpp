class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {

        int size = s.size();
        vector<string> result;
        for (int i = 1; i < size - 2; ++i) {
            vector<string> s2 = helper(s.substr(1, i));
            vector<string> s3 = helper(s.substr(i + 1, size - 2 - i));
            for (auto & str2 : s2) {
                for (auto & str3 : s3) {
                    result.push_back("(" + str2 + ", " + str3 + ")");
                }
            }
        }
        return result;
    }

private:
    vector<string> helper(string s) {

        int size = s.size();
        if (size == 0 || (size > 1 && s[0] == '0' && s[size - 1] == '0')) {
            return {};
        }

        if (size > 1 && s[0] == '0') {
            return { "0." + s.substr(1) };
        }
        
        if (size == 1 || s[size - 1] == '0') {
            return { s };
        }
        
        vector<string> result = { s };
        for (int i = 1; i < size; ++i) {
            result.push_back(s.substr(0, i) + '.' + s.substr(i));
        }
        return result;
    }
};
