class Solution {
public:
    string getSmallestString(int n, int k) {

        int k2 = k -= n;
        string result(n, 'a');
        for (int i = n - 1; i >= 0; i--) {
            int min = std::min(k2, 25);
            result[i] += min;
            k2 -= min;
        }
        return result;
    }
};
