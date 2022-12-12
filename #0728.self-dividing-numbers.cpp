class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> result;
        for (int i = left; i <= right; i++) {
            bool divided = true;
            int num = i;
            while (num) {
                if (num % 10 == 0
                    || i % (num % 10) != 0) {
                    divided = false;
                    break;
                }
                num /= 10;
            }

            if (divided) {
                result.push_back(i);
            }
        }
        return result;
    }
};
