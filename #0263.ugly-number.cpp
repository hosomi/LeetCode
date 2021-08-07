class Solution {
public:
    bool isUgly(int n) {

        vector<int> limited{2, 3, 5};
        for (int limit : limited) {
            while (n && n % limit == 0) {
                n /= limit;
            }
        }
        return n == 1;
    }
};
