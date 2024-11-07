class Solution {
public:
    int largestCombination(vector<int>& candidates) {

        vector<int> count(30, 0);
        for (int i : candidates) {
            for (int j = 0; j < 30; j++) {
                if ((i >> j) & 1) {
                    count[j]++;
                }
            }
        }
        return *max_element(count.begin(), count.end());
    }
};
