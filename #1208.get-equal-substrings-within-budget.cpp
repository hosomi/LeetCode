class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

        int index = 0;
        int cost = 0;
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            cost += abs(s[i] - t[i]);
            while(cost > maxCost) {
                cost -= std::abs(s[index] - t[index]);
                index++;
            }
            result = std::max(result, i - index + 1);
        }

        return result;
    }
};
