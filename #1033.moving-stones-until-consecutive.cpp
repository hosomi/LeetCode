class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {

        vector<int> stones = {a, b, c};
        std::sort(stones.begin(), stones.end());
        int first = (stones[1] - stones[0]-1) + (stones[2] - stones[1] - 1);
        int min;
        if (first == 0) {
            min = 0;
        } else {
            min = std::min(stones[1] - stones[0] - 1, stones[2] - stones[1] - 1);
            min = (min <= 1) ? 1 : 2;
        }
        return {min, first};
    }
};
