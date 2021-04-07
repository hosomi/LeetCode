class Solution {
public:
    int minDistance(string word1, string word2) {

        int size1 = word1.size();
        int size2 = word2.size();
        int** result = new int*[size1 + 1];
        for (int i = 0; i <= size1; ++i) {
            result[i] = new int[word2.size() + 1];
        }

        for (int i = 0; i <= size1; ++i) {
            result[i][0] = i;
            for (int j = 0; j <= size2; ++j) {
                result[0][j] = j;
                if (i != 0 && j != 0) {
                    if (word1[i - 1] == word2[j - 1]) {
                        result[i][j] = result[i - 1][j - 1];
                    } else {
                        result[i][j] = std::min({result[i - 1][j - 1], result[i - 1][j], result[i][j - 1]}) + 1;
                    }
                }
            }
        }
        return result[size1][size2]; 
    }
};
