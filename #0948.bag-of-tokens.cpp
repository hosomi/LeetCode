class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        int size = tokens.size();
        if (size == 0) {
            return 0;
        }
   
        std::sort(tokens.begin(), tokens.end());
        if (tokens[0] > power) {
            return 0;
        }

        int result = 0;
        int index = size - 1;
        for (int i = 0; i <= index; i++) {
            power -= tokens[i];
            if (power >= 0 ) {
                result ++;
            } else {
                power += tokens[index--];
            }
        }
        return result;
       
    }
};
