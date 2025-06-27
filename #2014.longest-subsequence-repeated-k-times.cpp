class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {

        queue<string> q;
        q.push("");
        string ans = "";
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string now = q.front();
                q.pop();
                for (char c = 'a'; c <= 'z'; c++) {
                    if (dfs(s,now + c, k)) {
                        ans=now+c,q.push(now + c);
                    }
                }
            }
        }
        return ans;
    }

private:
    bool dfs(string &s, string t, int k) {

        int n = s.length();
        int m = t.length();
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[j]) {
                j++;
            }
            if (j == m) {
                k--;
                j = 0;
            }
        }
        return k<=0;
    }
};
