class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());
        
        map<int, int> count;
        vector<int> key;
        for (int n : nums) {
            if (count.find(n) == count.end()) {
                count[n] = 1;
                key.push_back(n);
            } else {
                count[n]++;
            }
        }
        
        int size = key.size();
        int result = 0;
        for (int i = 1; i < size; i++) {
            int k1 = key[i];
            int k2 = key[i-1];
            if (k1 - k2 == 1) {
                result = std::max(result, count[k1] + count[k2]);
            }
        }
        return result;
    }
};
