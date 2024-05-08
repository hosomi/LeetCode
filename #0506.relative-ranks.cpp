class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        unordered_map<int,int> m;
        int n = score.size();
        for (int i = 0; i < n; i++) {
            m[score[i]] = i;
        }

        std::sort(score.begin(), score.end(), greater<int>());
        
        vector<string> results(score.size());
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                results[m[score[i]]] = "Gold Medal";
            } else if (i == 1) {
                results[m[score[i]]] = "Silver Medal";
            } else if (i == 2) {
                results[m[score[i]]] = "Bronze Medal";
            } else {
                results[m[score[i]]] = to_string(i + 1);
            }
        }
        return results;
    }
};
