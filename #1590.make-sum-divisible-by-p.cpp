class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int n = nums.size();
        int curr = 0;
        for (int i = 0; i < n; i++){
            curr += nums[i];
            curr %= p;
        }

        if (curr == 0) {
            return 0;
        }

        int need = curr;
        curr = 0;
        long long sum = 0;
        map<int, int> m;
        int result = n;
        m[0] =- 1;
        for (int i = 0; i < n; i++) {
            curr += nums[i];
            curr %= p;
            if (m.find((curr-need+p )%p) != m.end()) {
                result = std::min(result, i- m[(curr - need + p) % p]);
            } 
            m[curr] = i;   
        }
        return result == n ? -1 : result;
    }
};
