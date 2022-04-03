class Solution {
public:
    int concatenatedBinary(int n) {

        long long result = 0;     
        for (int i =1; i <=n; i++) {
            int cnt = 0;
            for (int j = i; j > 0;) {
                j = j>>1;
                cnt++;
            }
            result = ((result<<cnt) + i) % ((long long)1e9 + 7);
        }
        return result % ((long long)1e9 + 7);
    }
};
