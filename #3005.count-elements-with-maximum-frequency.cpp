class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        unordered_map<int, int>m;
        int max = 1;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            max = std::max(max, m[nums[i]]);
          
        }

        int cnt = 0;
        for (int i = 0; i < m.size(); i++) {
            if (m[i] == max) {
                cnt += m[i];
            }
        }
        return cnt;
    }
};
