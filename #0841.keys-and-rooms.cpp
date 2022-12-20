class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int> q;
        q.push(0);
        vector<bool> v(rooms.size(), false);
        v[0] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int r: rooms[u]) {
                if (!v[r]) {
                    v[r] = true;
                    q.push(r);
                }
            }
        }

        return all_of(begin(v), end(v), [](bool b) {
            return b;
        });
    }
};
