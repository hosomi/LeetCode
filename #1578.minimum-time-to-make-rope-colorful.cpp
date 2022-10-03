class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int size = colors.size();
        int max = 0;
        int sum = 0;
        int result = 0;
        for (int i = 0; i < size; ++i) {
            if (i - 1 >= 0 && colors[i] != colors[i - 1]) {
                result += sum - max;
                sum = max = 0;
            }
            sum += neededTime[i];
            max = std::max(max, neededTime[i]);
        }
        result += sum - max;
        return result;
    }
};
