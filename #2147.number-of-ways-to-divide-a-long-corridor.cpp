class Solution {
public:
    int numberOfWays(string corridor) {

        int count = 0;
        int left = 0;
        int size = corridor.size();
        long long result = 1;
        for (int i = 0; i < size; i++) {
            if (corridor[i] == 'S') {
                if (count == 1) {
                    left = i;
                    count++;
                    continue;
                }
                
                if (count == 2) {
                    result *= (i - left);
                    result %= 1000000007;
                    count = 1;
                    continue;
                }

                count++;
            }
        }

        if (count < 2) {
            return 0;
        }
        return result;
    }
};
