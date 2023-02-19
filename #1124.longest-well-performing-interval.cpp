class Solution {
public:
    int longestWPI(vector<int>& hours) {
        
        vector<int> v;
        for(auto &i: hours) {
            v.push_back(i > 8 ? 1 : -1);
        }

        unordered_map<int,int> mp;
        mp[0] = 0;
        int sum = 0;
        int result = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
            if (sum > 0) {
                result = std::max(result, i + 1);
            } else if (mp.count(sum - 1)) {
                result = std::max(result, i - mp[sum - 1]);
            }

            if (mp.count(sum) == 0) {
                mp[sum] = i;
            }
        }
        return result;
    }
};
