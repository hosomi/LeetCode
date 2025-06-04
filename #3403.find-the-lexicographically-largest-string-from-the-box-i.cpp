class Solution {
public:
    string answerString(string word, int numFriends) {

        if (numFriends == 1) {
            return word;
        }

        int n = word.size();
        int max_len = n - numFriends + 1;
        string res = "";
        for (int i = 0; i <= n - max_len; i++) {
            string curr = word.substr(i, max_len);
            if (curr > res) {
                res = curr;
            }
        }

        for (int i = max_len - 1; i > 0; i--) {
            string curr = word.substr(n - i);
            if (curr > res) {
                res = curr;
            }
        }

        return res;
    }
};
