class Solution {
public:
    int minDistance(string word1, string word2) {

        int size1 = word1.size();
        int size2 = word2.size();
        int work;
        vector<int> result(size2 + 1, 0);
        for (int i = 0; i <= size1; i++) {
            for (int j = 0; j <= size2; j++) {
                int tmp = result[j];
                if (i == 0 || j == 0) {
                    result[j] = i+j;
                } else if(word1[i-1] == word2[j - 1]) {
                    result[j] = work;
                } else {
                    result[j] = std::min(result[j], result[j - 1]) + 1;
                }
                work = tmp;
            }
        }
        return result[size2];
    }
};
