class Solution {
public:
    long long kMirror(int k, int n) {

        vector<long long> v;
        for (int i = 1; v.size() <= n + 3; i++) {
            for (const auto& xp : genPalin(i)) {
                if (isPalinK(xp, k)) v.push_back(xp);
            }
        }
        sort(v.begin(), v.end());
        return accumulate(begin(v), begin(v)+n, 0LL);
    }
private:
    array<long long, 2> genPalin(long long x) {

        long long reverse = 0;
        long long factor = 1;
        for (auto y = x; y; y /= 10, factor *= 10) {
            reverse =  reverse*10 +y%10;
        }
        return {x / 10  * factor + reverse, x * factor+reverse}; 
    }

    bool isPalinK(long long x, int base) {
        
        long long reverse = 0;
        for(auto y = x; y; y/=base)
            reverse = reverse*base + y%base;
        return reverse == x;
    }
};
