class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        vector<int>time(n, 1e9);
        time[0] = 0;
        time[firstPerson] = 0;
        vector<pair<int,int>> sides[n];
        for (int i = 0; i < meetings.size(); i++) {
            sides[meetings[i][0]].push_back({
                meetings[i][1], meetings[i][2]});
            sides[meetings[i][1]].push_back({
                meetings[i][0], meetings[i][2]});
        }

        priority_queue<pair<int, int>,
        vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});
        while (pq.size() != 0) {
            auto it = pq.top();
            int parent = it.second;
            int parent_time = it.first;
            pq.pop();
            for (int i = 0; i<sides[parent].size(); i++) {
                int child = sides[parent][i].first;
                int child_time = sides[parent][i].second;
                if (child_time >= parent_time) {
                    if (child_time<time[child]) {
                        pq.push({child_time, child});
                        time[child] = child_time;
                    }
                }
            }
        }

        vector<int> results;
        for (int i = 0; i < time.size(); i++) {
            if (time[i] != 1e9) {
                results.push_back(i);
            }
        }
        return results;
    }
};
