class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
 
        int n = fruits.size();
        int m = baskets.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (baskets[j] >= fruits[i]) {
                    baskets[j] = INT_MIN;
                    ++count;
                    break; 
                }
            }
        }
        
        return n - count;
    }
};
