class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int size = s.size();
        if (size != goal.size()) {
            return false;
        }
        
        int count = 0;
        unordered_map<int, int> counter;
        vector<int> diffs;
        bool dup = false;
        for (int i = 0; i < size; ++i) {
            if (s[i] != goal[i]) {
                diffs.push_back(i);
            }

            ++counter[s[i]];
            if (counter[s[i]] >= 2) {
                dup = true;
            }
        }
        
        if (diffs.empty() && dup) {
            return true;
        }
        
        if (diffs.size() != 2) {
            return false;
        }
        
        std::swap(s[diffs[0]], s[diffs[1]]);
        
        return s == goal;
    }
};
