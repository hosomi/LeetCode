class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        vector<int> freq(k);
        for (int i : arr) {
            freq[((i % k) + k) % k]++;
        }

        for (int i = 0; i < k - 1; i++) {
            if (i == 0) {
                if (freq[0] % 2) {
                    return false;
                }
            } else if (freq[i] != freq[k - i]) {
                return false;
            }
        }
        return true;
    }
};
