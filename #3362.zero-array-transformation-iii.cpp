class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        int m = queries.size();
        int j = 0;
        priority_queue<int> candidates;
        priority_queue<int, vector<int>, greater<>> chosen;
        int ans = 0;

        std::sort(queries.begin(), queries.end());

        for (int i = 0; i < n; i++) {
            while (j < m && queries[j][0] == i) {
                candidates.push(queries[j][1]);
                j++;
            }

            nums[i] -= chosen.size();
            while (nums[i] > 0 && !candidates.empty() &&
                   candidates.top() >= i) {
                chosen.push(candidates.top());
                candidates.pop();
                ans++;
                nums[i]--;
            }

            if (nums[i] > 0) {
                return -1;
            }
            
            while (!chosen.empty() && chosen.top() <= i) {
                chosen.pop();
            }
        }
        return m - ans;
    }
};
