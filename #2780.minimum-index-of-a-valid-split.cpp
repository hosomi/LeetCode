class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        int dominant = -1;
        int mx = 0;
        for (auto i : mp) {
            if (i.second > mx) {
                mx = i.second;
                dominant = i.first;
            }
        }
        
        unordered_map<int, int> mp1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == dominant) {
                cnt++;
            }
            mp1[i] = cnt;
        }
        
        cnt = 0;
        unordered_map<int, int> mp2;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == dominant) {
                cnt++;
            }
            mp2[i] = cnt;
        }
        
        for (int i=0; i<n-1; i++){
            if (mp1[i] * 2 > i + 1 && mp2[i + 1] * 2 > (n - i - 1)) {
                return i;
            }
        }
        return -1;
    }
};
