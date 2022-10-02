class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
    
        vector<int> v(target + 1);
        v[0] = 1;
        for (int i = 0; i < n; i++) {
            vector<int> cur(target + 1);
            for (int j = 1; j <= target; j++) { 
                for(int f = 1; f <= std::min(k, j); f++) { 
                    cur[j] = (cur[j] + v[j - f]) % (int)(1e9 + 7);
                }
            }
            v = cur;
        }
        return v.back();
    }
};
