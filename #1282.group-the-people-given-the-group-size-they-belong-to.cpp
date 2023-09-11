class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        int size = groupSizes.size();
        unordered_map<int, vector<int>> m;
        vector<vector<int>> results;
        for (int i = 0; i < size;i++) {
            m[groupSizes[i]].push_back(i);
            if (m[groupSizes[i]].size() == groupSizes[i]) {
                results.push_back(m[groupSizes[i]]);
                m[groupSizes[i]].clear();
            }
        }
        return results;
    }
};
