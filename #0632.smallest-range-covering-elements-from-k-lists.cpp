class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int row = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < nums[i].size(); j++){
                v.push_back({nums[i][j], i});
            }
        }

        std::sort(v.begin(), v.end());

        int n = v.size();
        int l = 0;
        int r = 0;
        int len = 1e9;
        vector<int> results(2);
        unordered_map<int, int> m;
        while (r < n) {
            m[v[r].second]++;   
            while(m.size() == row) {
                int L = v[r].first - v[l].first + 1;
                if (L < len){
                    len = L;
                    results[0] = (v[l].first);
                    results[1] = (v[r].first);
                }

                m[v[l].second]--;
                if (m[v[l].second] == 0) {
                    m.erase(v[l].second);
                }
                l++;
            }
            r++;
        }
        return results;
    }
};
