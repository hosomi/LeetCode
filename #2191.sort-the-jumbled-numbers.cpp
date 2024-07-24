class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            string str;
            for (int j = 0; j < s.size(); j++) {
                str += (mapping[s[j] - '0'] + '0');
            }
            int x = stoi(str);
            v.push_back({x, i});
        }

        std::sort(v.begin(), v.end());

        vector<int> results;
        for (auto i : v) {
            int k = nums[i.second];
            results.push_back(k);
        }
        return results;
    }
};
