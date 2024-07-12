class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        string target = (x >= y) ? "ab" : "ba";
        stack<pair<char,int>> st;
        int result = 0;
        int n = s.size();
        vector<int> ind(n, 0);
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (!st.empty()
                && st.top().first == target[0]
                && ch==target[1]) {
                result += std::max(x, y);
                ind[i] = 1;
                ind[st.top().second] = 1;
                st.pop();
            } else {
                st.push({ch, i});
            }
        }

        while (!st.empty()) {
            st.pop();
        }

        target = target == "ab" ? "ba" : "ab";

        for (int i = 0; i <n ; i++) {
            if (ind[i]) {
                continue;
            }

            char ch=s[i];
            if (!st.empty()
                && st.top().first == target[0]
                && ch == target[1]) {
                result += std::min(x, y);
                st.pop();
            } else {
                st.push({ch, i});
            }
        }
        return result;
    }
};
