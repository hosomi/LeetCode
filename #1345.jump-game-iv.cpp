class Solution {
public:
    int minJumps(vector<int>& arr) {

        int size = arr.size();
        unordered_map<int, unordered_set<int>> index;
        for (int i = 0; i < size; ++i) {
            index[arr[i]].insert(i);
        }

        vector<int> visited(size, false);
        int result = 0;
        int i = 0;
        visited[i] = true;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int jump = q.size();
            while (jump-- > 0) {
                i = q.front(); q.pop();
                if (i == size-1) {
                    return result;
                }

                if (i + 1 < size && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }

                for (auto it = index[arr[i]].begin(); it != index[arr[i]].end();) {
                    if (!visited[(*it)]) {
                        visited[(*it)] = true;
                        q.push((*it));
                        it = index[arr[i]].erase(it);
                    } else {
                        ++it;
                    }
                }
            }
            ++result;
        }
        return result;
    }
};
