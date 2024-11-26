class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> arr(n, 0);
        for (auto it : edges) {
            arr[it[1]] += 1;
        }

        int result = 0;
        int cnt = 0; 
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                cnt += 1;
                result = i;
            }
        }
        return cnt > 1 ? -1 : result;
    }
};
