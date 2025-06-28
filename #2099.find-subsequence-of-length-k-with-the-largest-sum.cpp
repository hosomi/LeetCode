class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        int n = nums.size();
        int i = 0;
        int t = k;
        vector<int> ans;
        while (t > 0) {
            ans.push_back(nums[i]);
            i++;
            t--;
        }
		
        for (int j = i; j < n; j++) {
            int min = min_element(ans.begin(), ans.end()) - ans.begin();
            if (ans[min] < nums[j]) {
                ans.erase(ans.begin()+min);
                ans.push_back(nums[j]);
            }
            
        }
        return ans;
    }
};
