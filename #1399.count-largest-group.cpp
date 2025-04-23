class Solution {
public:
    int countLargestGroup(int n) {

        vector<int> count(50, 0);
        int max = 0;
        for (int i = 1; i <= n; i++) {
            int num = i;
            int sum = 0;
            while (num > 0) {
                int temp = num % 10;
                sum += temp;
                num /= 10;
            }
            count[sum]++;
            max = std::max(max, count[sum]);
        }

        int ans = 0;
        for (int j : count) {
            if (j == max) {
                ans++;
            }
        }
        return ans;
    }
};
