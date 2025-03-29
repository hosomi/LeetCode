class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> primeFact(100001, 0);
        primeFact[1] = 0;
        for (int i=2; i < 100001; ++i) {
            if (primeFact[i] == 0) {
                primeFact[i] = 1;
                for (int k = 2 * i; k < 100001; k += i) {
                    primeFact[k]++;
                }
            }
        }

        vector<int> rgt(n);
        vector<int> lft(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty()
                && primeFact[nums[st.top()]] < primeFact[nums[i]]) {
                st.pop();
            }

            lft[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0;--i) {
            while (!st.empty()
                && primeFact[nums[st.top()]] <= primeFact[nums[i]]) {
                    st.pop();
            }

            rgt[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        vector<pair<int,int>> newNums;
        for (int i = 0; i < n; ++i) {
            newNums.push_back({nums[i],i});
        }

        std::sort(newNums.begin(), newNums.end());
        std::reverse(newNums.begin(), newNums.end());

        long long int score = 1;
        for (auto [val, idx] : newNums) {
            int low = lft[idx];
            int high = rgt[idx];
            long long int possible = (long long)(idx - low) * (long long)(high - idx);
            if (k <= possible) {
                return (score%mod * power((long long)val, k) %mod) % mod;
            }

            score = (score % mod * power((long long)val, possible) % mod) % mod;
            k -= possible;
        }
        return score;
    }

private:
    int mod = 1e9+7;
    long long int power(long long int x, long long int y) {

        long long int res = 1;
        x %= mod;   
        while (y > 0) {
            if (y & 1) {
                res = (res * x) % mod;
            }
            y = y>>1;
            x = ((x % mod) * (x % mod)) % mod; 
        }
        return res;
    }
};
