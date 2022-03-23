class Solution {
public:
    int brokenCalc(int startValue, int target) {

        int index = 0;
        while (target > startValue) {
            index++;
            if (target & 1) {
                target++;
            } else {
                target /= 2;
            }
        }
        return index + std::abs(startValue - target);
    }
};
