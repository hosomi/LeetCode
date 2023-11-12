class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        int size = routes.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < size; ++i) {
            for (int r : routes[i]){
                m[r].push_back(i); 
            }
        }
        
        queue<int> q;
        q.push(source);
        vector<bool> v(size, 0);
        int result = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int front = q.front();
                q.pop();
                if (front == target) {
                    return result;
                }

                vector<int> &buses = m[front]; 
                for (int x : buses) {
                    if (v[x]) {
                        continue;
                    }

                    for (int y : routes[x]) {
                        if (y != front) {
                            q.push(y);
                        }
                    }
                    v[x] = 1;
                }
            }
            result++;
        }
        return -1;
    }
};
