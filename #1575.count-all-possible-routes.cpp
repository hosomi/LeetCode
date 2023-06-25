class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        int size = locations.size();
        int MOD = 1e9 + 7;
        int memo[size][fuel+1];
        std::memset(memo, -1, sizeof memo);
        function<int(int,int)> solve = [&](int pos, int fuel) {

            if (fuel < 0) {
                return 0;
            }

            if (memo[pos][fuel] != -1) {
                return memo[pos][fuel];
            }

            int result = 0;
            if (pos == finish) {
                result = 1;
            }

            for (int i = 0; i < size; i++) {
                if (i == pos) {
                    continue;
                }
                result = (result + solve(i, fuel -
                    abs(locations[i] - locations[pos]))) % MOD;
            }
            return memo[pos][fuel] = result;
        };
        return solve(start, fuel);
    }
};
