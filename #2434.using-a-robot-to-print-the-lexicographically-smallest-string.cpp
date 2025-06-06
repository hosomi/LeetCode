class Solution {
public:
    string robotWithString(string s) {

        multiset<char> mst;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            mst.insert(s[i]);
        }

        string ans;
        int i = 0;
        while (i < s.size()) {
            while (st.size() && *mst.begin() >= st.top()) {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
            mst.erase(mst.find(s[i]));
            i++;
        }
        
        while(st.size()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
