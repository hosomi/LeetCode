class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        map<int, set<int>> mp;
        map<int, int> mp2;
        vector<int> res;
        for (auto q: queries) {
            if (mp2.find(q[0]) != mp2.end()) {
                int old_value = mp2[q[0]];
                mp[old_value].erase(q[0]);
                
                if (mp[old_value].empty()) {
                    mp.erase(old_value);
                }
            }
            
            mp[q[1]].insert(q[0]);
            mp2[q[0]] = q[1];
            res.push_back(mp.size());
        }
        return res;
    }
};
