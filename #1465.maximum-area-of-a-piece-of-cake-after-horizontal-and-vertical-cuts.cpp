class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {

        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        int size = horizontalCuts.size();
        int maxh = INT_MIN;
        for(int i = 0; i < size; i++) {
            maxh = std::max(maxh, horizontalCuts[i] - ((i > 0) ? horizontalCuts[i-1] : 0));
        }
        maxh = std::max(maxh, h - horizontalCuts[size - 1]);
        
        size = verticalCuts.size();
        int maxw = INT_MIN;
        for(int i = 0; i < size; i++) {
            maxw = std::max(maxw, verticalCuts[i] - ((i > 0) ? verticalCuts[i-1] : 0));
        }
        maxw = std::max(maxw, w - verticalCuts[size - 1]);

        return moduloMultiplication(maxh, maxw, 1e9+7);
    }

private:
    long long moduloMultiplication(long long maxh, long long maxw, long long mod) {
    
        long long result = 0;
        maxh %= mod; 
        while (maxw) { 
            if (maxw & 1) {
                result = (result + maxh) % mod; 
            }

            maxh = (2 * maxh) % mod; 
            maxw >>= 1;
        } 
        return result; 
    } 
};
