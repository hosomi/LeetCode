class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        set<int> s;
        map<int, int> m;
        for (auto it:matches) {
            s.insert(it[0]);
            m[it[1]]++;
        }
        
        vector<int> v;
        for (auto it:m) {
            if (it.second == 1) {
                v.push_back(it.first);
            }
            s.erase(it.first);
        }
        return {vector<int>(s.begin(), s.end()), v};
    }
};
