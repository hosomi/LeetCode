class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {

        int n = startTime.size();
        int ans = 0;
        vector<int> x;
        vector<int> pre(n);
        vector<int> suf(n + 5);
        x.push_back(startTime[0]);
        for (int i = 1; i < n; i++) {
            x.push_back(startTime[i] - endTime[i - 1]);
        }

        x.push_back(eventTime - endTime[n - 1]);

        for (int i = 0; i < n; i++) {
            pre[i] = max(x[i], (i ? pre[i - 1] : 0));
        }

        for (int i = n; ~i; i--) {
            suf[i] = max(x[i], suf[i + 1]);
        }

        for (int i = 0; i < x.size(); i++) {
            int sm = x[i] + (i + 1 < x.size() ? x[i + 1] : 0);

            if (i < n && max((i - 1 >= 0 ? pre[i - 1] : 0),
                suf[i + 2])>= endTime[i] - startTime[i]) {
                sm += endTime[i] - startTime[i];
            }

            ans = max(ans, sm);
        }
        return ans;
    }
};
