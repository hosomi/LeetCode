class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        

        unordered_map<string, bool> has;
        for (auto it : ideas) {
            has[it] = true;
        }

        set<char>s;
        for (auto it : ideas) {
            s.insert(it[0]);
        }

        int size = ideas.size();
        vector<vector<int>> v(26,vector<int>(26,0));
        long long result = 0;
        for (int i = 0; i < size; i++) {
            char f = ideas[i][0];
            for (auto it : s) {
                ideas[i][0] = it;
                if (has.find(ideas[i]) == has.end()) {
                    result += v[it-'a'][f-'a'];
                    v[f-'a'][it-'a']++;
                }
            }
        }
        result += result;
        return result;
    }
};
