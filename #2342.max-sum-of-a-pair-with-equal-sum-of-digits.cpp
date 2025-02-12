class Solution {
public:
    int maximumSum(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());

        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            string str = to_string(nums[i]);
            int x = 0;
            for (int j = 0; j < str.length(); j++) {
                x += str[j] - '0';
            }
            mp[x].push_back(nums[i]);
        }

        int ans = INT_MIN;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int sum = 0;
            if ((it->second).size() > 1) {
                for (int i = 0; i < (it->second).size() - 1; i++) {
                    sum = std::max(sum, (it->second)[i] + (it->second)[i + 1]);
                }
                ans = std::max(sum, ans);
            }
        }
        return ans == INT_MIN ? - 1 : ans;
    }
};
