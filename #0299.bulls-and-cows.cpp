class Solution {
public:
    string getHint(string secret, string guess) {

        int bull = 0;
        int cows = 0;
        int size = secret.size();
        vector<int> svec(10, 0);
        vector<int> gvec(10, 0);
        for (int i = 0; i < size; i++) {
            char s = secret[i];
            char g = guess[i];
            if (s == g) {
                bull++;
            } else {
                svec[s-'0']++;
                gvec[g-'0']++;
            }
        }

        for (int i = 0; i < 10; i++) {
            cows += std::min(svec[i], gvec[i]);
        }
        return to_string(bull) + "A" + to_string(cows) + "B";
    }
};
