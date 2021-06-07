class Solution {
public:
    int candy(vector<int>& ratings) {

        int size = ratings.size();
        vector<int> result(size, 1);
        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                result[i] = result[i - 1] + 1;
            }
        }

        int start =  size - 2;
        for (int i = start; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                result[i] = std::max(result[i], result[i + 1] + 1);
            }
        }
        return std::accumulate(std::begin(result), std::end(result), 0);
    }
};
