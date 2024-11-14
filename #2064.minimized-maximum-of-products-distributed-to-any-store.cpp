class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {

        int high = 1e5;
        int low = 1;
        while(low < high) {
            int mid = (high + low) / 2;
            int c = 0;
            for (auto i : quantities) {
                c += ((i + mid - 1) / mid);
            }
            if (c <= n) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
