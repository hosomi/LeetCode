class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        
        int s = 1;
        int e = 1e9;
        int ans = INT_MIN;
        while (s <= e) {
            int m = (s + e) / 2;
            if (maximumCandie(m, candies, k)) {
                ans = std::max(ans, m);
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }

private:
    bool maximumCandie(int x, vector<int> &c, long long k) {

        long long cnt = 0;
        for (int i : c) {
            cnt += i / x;
        }
        return !(cnt < k);
    }
};
