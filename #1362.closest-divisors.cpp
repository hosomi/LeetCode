class Solution {
public:
    vector<int> closestDivisors(int num) {

        int a = num + 1;
        int b = num + 2;
        int dist = INT_MAX;
        vector<int> result;
        int length = int(sqrt(a));
        for (int i = 1; i <= length; i++) {
            if (a % i == 0) {
                if (std::abs(i - a / i) < dist) {
                    dist = std::abs(i - b / i);
                    result = {i, a / i};
                }
            }
        }

        length = int(sqrt(b));
        for (int i = 1; i <= length; i++) {
            if (b % i == 0) {
                if (std::abs(i - b / i) < dist) {
                    dist = std::abs(i - b / i);
                    result = {i, b / i};
                }
            }
        }
        return result;
    }
};
