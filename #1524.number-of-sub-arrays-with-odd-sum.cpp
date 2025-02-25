class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        long long sum = 0;
        long long even = 0;
        long long odd = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        return odd + (odd * even) % 1000000007;
    }
};
