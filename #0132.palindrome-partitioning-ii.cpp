class Solution {
public:
    int minCut(string s) {

        int size = s.size();
        vector<int> result(size);
        std::iota(result.begin(), result.end(), 0);
        int index;
        int minimum;
        for (int i = 1; i < size; i++) {
            index = 0;
            while (i - index >= 0 && i + index < size && s[i - index] == s[i + index]) {
                minimum = (i - index - 1 >= 0) ? result[i - index - 1] + 1 : 0;
                result[i + index] = std::min(result[i + index], minimum);
                index++;
            }

            index = 0;

            while (i - index - 1 >= 0 && i + index < size && s[i - index - 1] == s[i + index]) {
                minimum = (i - index - 1 - 1 >= 0) ? result[i - index - 1 - 1] + 1 : 0;
                result[i + index] = std::min(result[i + index], minimum);
                index++;
            }
        }
        return result[size - 1];
    }
};
