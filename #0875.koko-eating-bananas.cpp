class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int result = 1;
        int pile = *max_element(piles.begin(), piles.end());
        while (result < pile) {
            int mid = (result + pile) / 2;
            int total = 0;
            for (int p : piles) {
                total += (p + mid - 1) / mid;
            }
            if (total > h) {
                result = mid + 1;
            } else {
                pile = mid;
            }
        }
        return result;
    }
};
