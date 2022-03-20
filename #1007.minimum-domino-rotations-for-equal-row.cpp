class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        int size = tops.size();
        int top = 0;
        int bottom = 0;
        for (int i = 0; i < size; i++) {
            if (tops[i] == tops[0] || bottoms[i] == tops[0]) {
                if (tops[i] != tops[0]) {
                    top++;
                }
                if (bottoms[i] != tops[0]) {
                    bottom++;
                }
            } else {
                break;
            }

            if (i == size-1) {
                return std::min(top, bottom);
            }
        }

        top = 0;
        bottom = 0;
        for (int i = 0; i < size; i++) {
            if (tops[i] == bottoms[0] || bottoms[i] == bottoms[0]) {
                if (tops[i] != bottoms[0]) {
                    top++;
                }
                if (bottoms[i] != bottoms[0]) {
                    bottom++;
                }
            } else {
                break;
            }

            if (i == size - 1) {
                return std::min(top, bottom);
            }
        }
        return -1;
    }
};
