class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        std::sort(meetings.begin(), meetings.end());
        
        int ans = 0;
        if (meetings[0][0] != 1) {
            ans += meetings[0][0] - 1;
        }

        vector<int> v;
        v.push_back(meetings[0][1]);
        
        int n = meetings.size();
        for (int i = 1; i < n; i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            if (!v.empty() && v.back() < start) {
                ans += start - v.back() - 1; 
                v.back() = end;
            } else {
                v.back() = max(v.back(),end);
            }
        }
        
        ans += days - v.back(); 
        return ans;
    }
};
