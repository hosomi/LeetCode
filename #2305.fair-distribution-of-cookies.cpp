class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        
        std::sort(cookies.rbegin(), cookies.rend());
    
        int result = INT_MAX;
        vector<int> check(k, 0);
        solve(cookies, 0, check, result, 0);
        return result;
    }

private:
    void solve(vector<int>&cookies, int index,
        vector<int> check, int &result, int maxval) {

        if (index >= cookies.size()) {
            result = std::min(maxval, result);
            return;
        }

        for (int i = 0; i < check.size(); i++) {
            check[i] += cookies[index];
            solve(cookies, index + 1, check, result,
                std::max(check[i], maxval));
            check[i] = check[i] - cookies[index];
            if (result <= maxval) {
                return;
            }
        }
    }
};
