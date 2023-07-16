class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        unordered_map<string, int> mp;
        int size1 = req_skills.size();
        int size2 = people.size();
        vector<vector<int> > dp(1<<size1, vector<int>(1000));
        int skill[size2];
        fill(skill, skill + size2, 0);
        dp[0].clear();
        
        for (int i = 0; i < size1; i++) {
            mp[req_skills[i]] = i;
        }
        
        for (int i = 0; i < size2; i++) {
            for (auto x: people[i]) {
                skill[i] |= 1<<mp[x];
            }
        }
        
        for (int i = 1; i < 1 << size1; i++) {
            for (int j = 0; j < size2; j++) {
                if ((skill[j] & i) != skill[j]) {
                    continue;
                }
                
                int mask = skill[j];
                for (int k = mask; k > 0; k = (k - 1) & mask) {
                    int temp = i & (~k);
                    if (dp[i].size() > dp[temp].size() + 1) {
                        dp[i] = dp[temp];
                        dp[i].push_back(j);
                    }
                }
                
            }
        }
        return dp[(1 << size1) - 1];   
    }
};
