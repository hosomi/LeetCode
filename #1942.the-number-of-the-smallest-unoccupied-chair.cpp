class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int timeFriend = times[targetFriend][0];
        int n = times.size();
 
        std::sort(times.begin(), times.end());

        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> notAvailable;

        for (auto &t : times) {
            while (!notAvailable.empty() && notAvailable.top().first<= t[0]) {
                available.push(notAvailable.top().second);
                notAvailable.pop();
            }

            if (t[0] == timeFriend) {
                break;
            }

            if (available.empty()) {
                notAvailable.push({t[1], notAvailable.size()});
            } else {
                notAvailable.push({t[1], available.top()});
                available.pop();
            }
        }
        return available.empty() ? notAvailable.size() : available.top();
    }
};
