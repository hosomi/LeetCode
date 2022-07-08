class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {

        this->m = m;
        this->n = n;
        this->target = target;
        
        paints = vector<vector<vector<int>>>(m, vector<vector<int>>(target+1, vector<int>(n+2, 0)));
        
        int result = dfs(houses, cost, 0, target, -1);
        return (result >= MAX) ? -1 : result;
    }

private:
    int MAX = 1e6+1;
    int m;
    int n;
    int target;
    vector<vector<vector<int>>> paints;
    
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int start, int t, int prevColor) {

        if (t < 0 || t > m - start) {
            return MAX;
        }
        
        if (start == m) {
            return (t == 0) ? 0 : MAX;
        }

        if (paints[start][t][prevColor + 1] != 0) {
            return paints[start][t][prevColor + 1];
        }
        
        if (houses[start] != 0) {
            paints[start][t][prevColor+1] = dfs(houses, cost, start + 1,
                t - (houses[start] != prevColor), houses[start]);
            return paints[start][t][prevColor + 1];
        }
        
        int result = MAX;
        for (int color = 1; color <= n; color++) {
            result = std::min(result,
                cost[start][color-1] + dfs(houses, cost, start+1, t - (color != prevColor), color));
        }
        return paints[start][t][prevColor+1] = result;
    };
};
