class Solution {
public:
    int colorTheGrid(int m, int n) {

        memset(dp,-1,sizeof(dp));
        vector<string> v;
        string s="";
        genrate(0,s,v,'M',m);
        return  find(0,v,-1,m,n)%mod;
    }

private:
    int dp[1001][50];
    int mod = 1e9+7;
    void genrate(int i,string& s,vector<string>& v,char ch,int m){
        
        if (i == m) {
            v.push_back(s);
            return;
        }

        if (ch != 'R'){
            s += 'R';
            genrate(i + 1, s, v, 'R', m);
            s.pop_back();
        }

        if (ch != 'G') {
            s += 'G';
            genrate(i + 1, s, v, 'G', m);
             s.pop_back();
        }

        if (ch != 'B') {
            s += 'B';
            genrate(i + 1, s, v, 'B', m);
            s.pop_back();
        }
    }

    int find(int i, vector<string>& v, int pre, int m, int n) {
        
        if (i == n) {
            return 1;
        }

        if (dp[i][pre + 1] != -1) {
            return dp[i][pre + 1];
        }

        long long ways = 0;
        string last;
        if (pre != -1) {
            last = v[pre];
        }

        for (int j = 0; j < v.size(); j++) {
            bool same = false;
            if (pre != -1) {
                for (int k = 0; k < m; k++) {
                    if (last[k] == v[j][k]) {
                        same = true;
                        break;
                    }
                }
            }
            if (!same) {
                ways = (ways + find(i + 1, v, j, m, n)) % mod;
            }
               
            
        }
        return dp[i][pre + 1] = ways;
    }
};
