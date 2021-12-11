class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {

        if (a > b) {
            swap(a, b);
        }

        uint64_t lcm = std::lcm(a, b);
        uint64_t low = 0;
        uint64_t high = (uint64_t)n * a;
        while (low < high) {
            uint64_t mid = low + (high - low) / 2;
            uint64_t count = mid / a + mid / b - mid / lcm;
            if (count < n) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low % 1000000007;
    }
};
