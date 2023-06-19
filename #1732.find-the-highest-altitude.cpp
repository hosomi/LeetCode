class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int cur = 0;
        int max = 0;
        for (int g : gain) {
            cur += g;
            max = std::max(max, cur);
        }
        return max;
    }
};
