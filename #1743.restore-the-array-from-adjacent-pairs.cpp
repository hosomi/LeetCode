class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairsacentPairs) {

        unordered_map<int,vector<int>> m;
        for (auto adj: adjacentPairsacentPairs) {
            m[adj[0]].push_back(adj[1]);
            m[adj[1]].push_back(adj[0]);
        }

        vector<int> results;
        for(auto a : m) {
            if (a.second.size() == 1) {
                results.push_back(a.first);
                break;
            }
        }

        int size = adjacentPairsacentPairs.size() + 1;
        results.push_back(m[results.back()][0]);
        while (results.size() != size) {
            int pr = results[results.size() - 2];
            int ba = results.back();
            results.push_back(pr == m[ba][0] ? m[ba][1] : m[ba][0]);
        }
        return results;
    }
};
