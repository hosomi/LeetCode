class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {

        vector<int> ans;
        vector<int> count(32, 0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            int max = 0;
            for(int j=0;j<32;j++){
                if ((1<<j) & nums[i]){
                    count[j]=i;
                }
            }

            for (int j = 0; j < 32; j++) {
                max = std::max(max, count[j]);
            }
            
            ans.push_back(std::max(max - i + 1, 1));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
