class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        int len_low = std::log10(low) + 1;
        int len_high = std::log10(high) + 1;
        vector<int> result;
        for (int i = len_low; i <= len_high; ++i) {
            int start = (i == len_low) ? low / std::pow(10, len_low-1) : 1;
            int index = 0;
            for (int j = start; j + i - 1 <= 9; ++j) {
                index = 0;
                for (int k = 0; k < i; ++k) {
                    index += std::pow(10, i - 1 - k) * (j + k);
                }
                if (index >= low && index <= high) {
                    result.push_back(index);
                }
            }
        }
        return result;
    }
};
