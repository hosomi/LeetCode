class Solution {
public:
    int partitionString(string s) {
        
        set <char> st;
        int result = 1;
        for (char c : s) {
            if (st.find(c) != st.end()) {
                st.clear();
                result++;
            }
            st.insert(c);
        }
        return result;
    }
};
