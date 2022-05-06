class Solution {
public:
    string removeDuplicates(string s, int k) {

        vector<pair<char, short>> st;
        for (auto ch : s) {
            if (st.empty() || st.back().first != ch) {
                st.push_back({ ch, 0 });
            }
            if (++st.back().second == k) {
                st.pop_back();
            }
        }

        string result;
        for (auto& p : st) {
            result += string(p.second, p.first);
        }
        return result;
    }
};
