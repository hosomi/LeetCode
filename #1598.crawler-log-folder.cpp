class Solution {
public:
    int minOperations(vector<string>& logs) {

        stack<string> st;
        for(const string& log : logs){
            if (log == "./") { 
            } else if(log == "../") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(log);
            }
        }
        return st.size();
    }
};
