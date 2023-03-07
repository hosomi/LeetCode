class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long k = 0; 
        long long n = 1e17;
        for (long long b = n / 2; b >= 1; b /= 2) {
            while (k + b < n) {
                long long total = 0;
                for (auto t : time) {
                    if (total >= totalTrips) {
                        break;
                    }
                    total += (k+b)/t;
                } 

                if (total < totalTrips) {
                    k+=b;
                } else {
                    break;
                }
            }
        }

        return k + 1;
    }
};
