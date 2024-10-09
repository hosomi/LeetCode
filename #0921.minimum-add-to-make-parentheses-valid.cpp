class Solution {
public:
    int minAddToMakeValid(string s) {

        int result = 0;
        vector<char> v;
        for (auto &i : s) {
            if (i == '(') {
                v.push_back(i);
            } else {
                if (v.empty()) {
                    result++;
                } else {
                    v.pop_back();
                }
            }
        }
        return result + v.size();
    }
};
