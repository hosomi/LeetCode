class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        int m = rolls.size();
        int sum = ( (m + n) * mean)
            - accumulate(rolls.begin(), rolls.end(), 0);
        if (sum < n || sum > 6 * n) {
            return {};
        }

        vector<int> results(n, sum / n);
        int x = sum % n;
        int i = 0;
        while (x--) {
            results[i++]++;
        }
        return results;
    }
};
