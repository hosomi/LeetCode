class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<string> results;
        vector<pair<int, string>> v;
        for (int i = 0; i < names.size(); i++) {
            v.push_back({heights[i], names[i]});
        }

        std::sort(v.rbegin(), v.rend());
        
        for (auto & x : v) {
            results.push_back(x.second);
        }
        return results;
    }
};
