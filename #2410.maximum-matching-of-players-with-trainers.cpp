class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));

        int ans = 0;
        int i = 0;
        int j = 0;
        int m = players.size();
        int n = trainers.size();
        while (i < m && j < n) {
            if (players[i] <= trainers[j]) {
                ans++;
                i++;
            }
            j++;
        }
        return ans;  
    }
};
