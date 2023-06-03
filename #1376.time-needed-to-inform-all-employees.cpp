class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            map[manager[i]].push_back(i);
        }
        
        stack<pair<int, int>> stk;
        int result = 0;
        stk.push(make_pair(headID, 0));
        while (!stk.empty()) {
            pair<int,int> p = stk.top(); 
            stk.pop();
            int first = p.first;
            int second = p.second;
            result = std::max(result, second);
            for (int m : map[first]) {
                stk.push(make_pair(m, second + informTime[first]));
            }
        }
        return result;
    }
};
