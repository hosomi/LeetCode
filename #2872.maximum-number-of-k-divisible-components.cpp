class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        vector<vector<int>> arr(n);
        for (int i = 0; i < edges.size(); i++) {
            arr[edges[i][0]].push_back(edges[i][1]);
            arr[edges[i][1]].push_back(edges[i][0]);
        }

        vector<long long> results = dfs(arr, - 1, 0, values, k);
        return results[0];
    }

private:
    vector<long long> dfs(vector<vector<int>>& arr,
        int par, int curr, vector<int>& values,int k) {

        long long count = 0;
        long long sum = 0;
        for (long long i: arr[curr]) {
            if (i == par) {
                continue;
            }

            vector<long long> temp = dfs(arr, curr, i, values, k);
            sum += temp[1];
            count += temp[0];
        }

        if ((sum + values[curr]) % k == 0) {
            return {count + 1, 0};
        }
        return {count,sum+values[curr]};
    }
};
