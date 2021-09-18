class Solution {
public:
    int numSquares(int n) {

        int i;
        int min;
        vector<int> result = {0};
        while(result.size() <= n){
            i = result.size();
            min = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                min = std::min(min, result[i - j * j] + 1);
            }
            result.push_back(min);
        }
        return result[n];
    }
};
