class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
     
        for (vector<int>& domino : dominoes) {
            std::sort(domino.begin(), domino.end());
        }

        std::sort(dominoes.begin(), dominoes.end());
        int size = dominoes.size();
        int group = 0;
        int pair = 0;
        bool isFirst = true;
        vector<int> cur = dominoes[0];
        for (int i = 1; i < size; i++) {
            if (dominoes[i] == cur) {
                group++;
                if (isFirst) {
                    group++;
                    isFirst = false;
                }
            } else {
                cur = dominoes[i];
                isFirst = true;
                pair += group * (group - 1) / 2;
                group = 0;
            }
        }

        pair += group * (group-1) / 2;
        return pair;
    }
};
