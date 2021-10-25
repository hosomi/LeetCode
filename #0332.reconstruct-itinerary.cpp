class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, multiset<string>> um;
        for(vector<string>& ticket : tickets){
            um[ticket[0]].insert(ticket[1]);
        }

        vector<string> result;
        stack<string> st;
        st.push("JFK");
        string begin;
        while (!st.empty()) {
            while (um.find(st.top()) != um.end()
                   && !um[st.top()].empty()) {
                begin = *um[st.top()].begin();
                um[st.top()].erase(um[st.top()].begin());
                st.push(begin);
            }
            result.insert(result.begin(), st.top());
            st.pop();
        }
        return result;
    }
};
