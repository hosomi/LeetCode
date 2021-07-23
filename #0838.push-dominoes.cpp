class Solution {
public:
    string pushDominoes(string dominoes) {

        int size = dominoes.size();
        vector<int> L(size, INT_MAX);
        vector<int> R(size, INT_MAX);
        for (int i = 0; i < size; ++i) {
            if (dominoes[i] == 'L') {
                L[i] = 0;
                for (int j = i - 1; j >= 0 && dominoes[j] == '.'; --j) {
                    L[j] = L[j + 1] + 1;
                }
            } else if (dominoes[i] == 'R') {
                R[i] = 0;
                for (int j = i + 1; j < size && dominoes[j] == '.'; ++j) {
                    R[j] = R[j - 1] + 1;
                }
            }
        }

        for (int i = 0; i < size; ++i) {
            if (L[i] < R[i]) {
                dominoes[i] = 'L';
            } else if (L[i] > R[i]) {
                dominoes[i] = 'R';
            }
        }
        return dominoes;
    }
};
