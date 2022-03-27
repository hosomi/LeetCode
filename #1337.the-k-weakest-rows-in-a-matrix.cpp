class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        int size = mat.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < size; i++) {
            pq.push(std::accumulate(
                mat[i].begin(), mat[i].end(), 0) * 100 + i
            );
        }

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = pq.top() % 100;
            pq.pop();
        }
        return result;
    }
};
