class Solution {
public:
    int flipLights(int n, int presses) {

        if (n > 6) {
            n = n % 6 + 6;
        }

        unordered_set<int> result{(1 << n) - 1};
        auto flips = [n](int flip, int start, int step) {
            for (int i = start; i < n; i += step) {
                flip ^= (1 << i);
            }
            return flip;
        };

        for (int i = 0; i < presses; ++i) {
            unordered_set<int> result2;
            for (int flip : result) {
                result2.insert(flips(flip, 0, 1));
                result2.insert(flips(flip, 0, 2));
                result2.insert(flips(flip, 1, 2));
                result2.insert(flips(flip, 0, 3));
            }
            result.swap(result2);
        }
        return result.size();
    }
};
