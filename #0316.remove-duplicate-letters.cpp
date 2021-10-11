class Solution {
public:
    string removeDuplicateLetters(string s) {

        int size = s.size();
        if (size == 0) {
            return "";
        }

        vector<int> result(26, 0);
        for (char& c : s) {
            ++result[c-'a'];
        }

        int index = 0;
        for (int i = 0; i < size; ++i) {
            if (s[i] < s[index]) {
                index = i;
            }
            --result[s[i]-'a'];
            if (result[s[i]-'a'] == 0) {
                break;
            }
        }

        string str = s.substr(index + 1);
        auto it = remove(str.begin(), str.end(), s[index]);
        str = std::string(str.begin(), it);
        return s[index] + removeDuplicateLetters(str);
    }
};
