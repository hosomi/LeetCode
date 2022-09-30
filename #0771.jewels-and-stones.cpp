class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        int result = 0;
        for (char s : stones) {
            if (jewels.find(string(1, s)) != string::npos) {
                result++;
            }
        }
        return result;
    }
};
