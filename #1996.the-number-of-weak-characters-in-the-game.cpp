class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {

        int size = properties.size();
        for (int i = 0; i < size; i++) {
            properties[i][1] *= -1;
        }

        std::sort(properties.begin(), properties.end());

        int max = -1;
        int result = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (-properties[i][1] < max) {
                result++;
            }
            max = std::max(max, -properties[i][1]);
        }
        return result;
    }
};
