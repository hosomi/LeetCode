class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {

        priority_queue<pair<int, int>,
            vector<pair<int,int>>, greater<pair<int, int>>> pq;
        vector<int> results(queries.size(), -1);
        unordered_map<int, vector<pair<int, int>>> m;
        for (int q = 0; q<queries.size(); q++) {
            int i = queries[q][0];
            int j = queries[q][1];
            if (i < j && heights[j] > heights[i]) {
                results[q] = j;
            } else if (i > j && heights[j] < heights[i]) {
                results[q] = i;
            } else if (i == j) {
                results[q] = i;
            } else {
                m[max(i, j)].push_back({std::max(heights[i], heights[j]), q});
            }
        }
        
        for (int i = 0; i < heights.size(); i++) {
            while (!pq.empty() && pq.top().first < heights[i]) {
                results[pq.top().second] = i;
                pq.pop();
            }
            for(auto a : m[i]) {
                pq.push(a);
            }
        }
        return results;
    }
};
