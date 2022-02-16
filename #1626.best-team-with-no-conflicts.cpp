class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        int size = scores.size();
        vector<int> players(size);
        std::iota(players.begin(), players.end(), 0);
        std::sort(players.begin(), players.end(), [&](int& p1, int& p2) {
            return (ages[p1] == ages[p2]) ? (scores[p1] < scores[p2]) : (ages[p1] < ages[p2]);
        });
        vector<int> result(size);
        int pi, pj;
        for (int i = 0; i < size; ++i) {
            pi = players[i];
            result[i] = scores[pi];
            for (int j = 0; j < i; ++j) {
                pj = players[j];
                if (scores[pj] <= scores[pi]) {
                    result[i] = std::max(result[i], result[j] + scores[pi]);
                }
            }
        }
        return *std::max_element(result.begin(), result.end());
    }
};
