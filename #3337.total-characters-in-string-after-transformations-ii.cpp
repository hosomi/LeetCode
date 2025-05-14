class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {

        long M = 1000000007;
        long currTfm[2][26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < i; j++) {
                currTfm[0][i][j] = 0;
            }
            currTfm[0][i][i] = 1;
            for (int j = i + 1; j < 26; j++) {
                currTfm[0][i][j] = 0;
            }
        }

        long binMemo[31][26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                binMemo[0][i][j] = 0;
            }
            for (int j = 0; j < nums[i]; j++) {
                binMemo[0][i][(1 + i + j) % 26] = 1;
            }
        }

        for (int p = 1; p < 31; p++) {
            long (*prev)[26] = binMemo[p - 1];
            long (*curr)[26] = binMemo[p];
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    long& currCell = curr[i][j];
                    currCell = 0;
                    for (int k = 0; k < 26; k++) {
                        currCell += (prev[k][j] * prev[i][k]);
                        currCell %= M;
                    }
                }
            }
        }

        long retIdx = 0;
        for (int p = 0; p < 31; p++) {
            if (t & (1 << p)) {
                retIdx = !retIdx;
                long (*prev)[26] = currTfm[!retIdx];
                long (*curr)[26] = currTfm[retIdx];
                long (*currPow)[26] = binMemo[p];
                for (int i = 0; i < 26; i++) {
                    for (int j = 0; j < 26; j++) {
                        long& currCell = curr[i][j];
                        currCell = 0;
                        for (int k = 0; k < 26; k++) {
                            currCell += (prev[k][j] * currPow[i][k]);
                            currCell %= M;
                        }
                    }
                }
            }
        }

        long result = 0;
        for (char c : s) {
            for (long generated : currTfm[retIdx][c - 'a']) {
                result += generated;
                result %= M;
            }
        }
        return result;
    }
};
