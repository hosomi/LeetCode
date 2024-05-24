class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        vector<int> v(26, 0);
        for (auto &letter : letters) {
            v[letter - 'a']++;
        }

        int result = 0;
        int n = words.size();
        maxScoreWords(0, n, v, score, result, 0, words);
        return result;
    }

private:
    void maxScoreWords(int i, int &n, vector<int>& v,
        vector<int>& score, int &result,
        int sum, vector<string>& words) {

        result = std::max(result, sum);
        if (i >= n) {
            return;
        }

        vector<int> temp = v;
        int j = 0;
        int scores = 0;
        for (j = 0; j < words[i].length(); j++) {
            temp[words[i][j] - 'a']--;
            scores += score[words[i][j] - 'a'];
            if (temp[words[i][j] - 'a'] < 0) {
                break;
            }
        }

        if (j == words[i].length()) {
            maxScoreWords(i + 1, n, temp, score, result, sum + scores, words);
        }

        maxScoreWords(i + 1, n, v, score, result, sum, words);
    }
};
