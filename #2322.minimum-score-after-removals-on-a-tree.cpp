class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {

        int n = nums.size();
        vector<vector<int>>adjList(n);
        for(auto it : edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        xor_.resize(n);
        in.resize(n);
        out.resize(n);
        precompute(adjList , 1 , nums);
        inout(adjList , 1 );
        int uni = xor_[1];
        int res = INT_MAX ;
        for(int i = 0 ; i < n ; i++){
            for (int j = i + 1 ; j < n ; j++) {
                if (i == 1 || j == 1) {
                    continue;
                }
                
                int first = xor_[i];
                int second = xor_[j];
                if(in[i] <= in[j] && out[i] >= out[j]){
                    uni ^= first ;
                    first ^= second ;
                    int mx = max({first , second , uni});
                    int mn = min({first , second , uni});
                    res = min(res , mx - mn) ;
                } else if(in[j] <= in[i] && out[j] >= out[i]){
                    uni ^= second ;
                    second ^= first ;
                    int mx = max({first , second , uni});
                    int mn = min({first , second , uni});
                    res = min(res , mx - mn);
                } else{
                    uni ^= first ;
                    uni ^= second ;
                    int mx = max({first , second , uni});
                    int mn = min({first , second , uni});
                    res = min(res , mx - mn);
                }
                uni = xor_[1];
            }
        }
        return res;
    }

private:
    vector<int>xor_;
    int time = 0;
    vector<int>in , out;

    void inout(vector<vector<int>>&adjList , int source , int parent = -1) {

        in[source] = ++time ;
        for (auto it : adjList[source]) {
            if (it != parent) {
                inout(adjList , it , source);
            }
        }
        out[source] = ++time ;
    }

    void precompute(vector<vector<int>>&adjList , int source , vector<int>&nums , int parent = -1) {

        int ans = nums[source];
        for (auto it : adjList[source]) {
            if (it != parent) {
                precompute(adjList , it , nums , source);
                ans ^= xor_[it];
            }
        }
        
        xor_[source] = ans ; 
    }
};
