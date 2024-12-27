class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        int cnt = 0;
        int result = 0;
        for (int value : values) {
            result = std::max(result, cnt + value);
            cnt = std::max(cnt, value) - 1;
        }
        return result;
    }
};
