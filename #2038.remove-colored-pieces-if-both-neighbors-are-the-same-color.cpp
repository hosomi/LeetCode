class Solution {
public:
    bool winnerOfGame(string colors) {
        int size = colors.size();
        int left = 0;
        int right = 0;
        for (int i = 1; i < size; i++) {
            if (colors[i - 1] == colors[i]
                && colors[i+1]==colors[i]) {
                if (colors[i] == 'A') {
                    left++;
                } else {
                    right++;
                }
            }
        }
        return left > right;
    }
};
