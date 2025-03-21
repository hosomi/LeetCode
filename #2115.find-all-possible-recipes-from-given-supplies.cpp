class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        queue<string> q(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> mp;
        for (int i = 0; i < recipes.size(); i++) {
            for (auto& j : ingredients[i]) {
                adj[j].push_back(recipes[i]);
                mp[recipes[i]]++;
            }
        }
        
        vector<string> ans;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            for (auto& n : adj[node]) {
                mp[n]--;
                if (mp[n] == 0) {
                    ans.push_back(n);
                    q.push(n);
                }
            }
        }
        return ans;
    }
};
