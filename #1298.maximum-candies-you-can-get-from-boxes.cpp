class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

        int n=candies.size();
        vector<int> vis(n,0);
        queue<int> q;
        unordered_set<int> boxFound, keyFound;
        int ans = 0;
        for (int i = 0 ; i < initialBoxes.size(); i++) {
            if (status[initialBoxes[i]] == 1) {
                q.push(initialBoxes[i]);
            } else {
                boxFound.insert(initialBoxes[i]);
            }
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            vis[x] = 1;
            ans += (candies[x]);
            for (auto y : containedBoxes[x]) {
                if (status[y] && !vis[y]){
                    q.push(y);
                } else if (status[y] == 0) {
                    boxFound.insert(y);
                }
            }

            for (auto y : keys[x]) {
                keyFound.insert(y);
            }

            for (auto y : keyFound) {
                if (boxFound.count(y)) { 
                    q.push(y);
                    boxFound.erase(y); 
                }
            }
        }
        return ans;
    }
};
