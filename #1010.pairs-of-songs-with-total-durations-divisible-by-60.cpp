class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {

        int result = 0;
        vector<int> count(60);
        for (int t : time) {
            result += count[(60 - t % 60) % 60];
            count[t%60]++;
        }
        return result;
    }
};
