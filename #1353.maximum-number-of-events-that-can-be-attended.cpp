class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {


        sort(events.begin() , events.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        int i = 0;
        for (int d = 1; d <= 100000; d++) {
            while(!pq.empty() && d>pq.top()) {
                pq.pop();
            }

            while (i<events.size() && events[i][0] == d) {
                pq.push(events[i][1]);
                i++;
            }
            
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
            
            if (pq.empty() && i == events.size()) {
                break;
            }
            
        }
        return ans;
    }
};
