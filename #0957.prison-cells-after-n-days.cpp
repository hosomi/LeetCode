class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {

        if (n <= 0) {
            return cells;
        }

        int size = cells.size();
        vector<vector<int>> states;
        vector<int> curr_state(size, 0);
        vector<int> prev_state = cells;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < size - 1; j++) {
                curr_state[j] = prev_state[j - 1] == prev_state[j + 1];
            }

            if (!states.empty() && states[0] == curr_state) {
                return states[(n - 1) % states.size()];
            }
            
            states.emplace_back(curr_state);
            prev_state = curr_state;
        }
        return curr_state; 
    }
};
