class Solution {
public:

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        if (buildings.empty()) {
            return {};
        }

        multiset<pair<int, int>> ms;
        for (auto bd : buildings){
            ms.insert(make_pair(bd[0], -bd[2]));
            ms.insert(make_pair(bd[1], bd[2]));
        }

        vector<vector<int>> result;
        multiset<int> height = {0};
        int i = 0;
        for (auto s:ms) {
            if (s.second < 0) {
                height.insert(-s.second);
            } else {
                height.erase(height.find(s.second));
            }

            if (i != *height.rbegin()) {
                result.push_back({s.first, *height.rbegin()});
            }

            i = *height.rbegin();
        }

        return result;
    }
};
