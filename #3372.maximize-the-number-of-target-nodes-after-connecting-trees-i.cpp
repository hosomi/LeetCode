class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {

        int n1 = edges1.size() + 1; 
        int n2 = edges2.size() + 1;
        vector<vector<int>> nums2(n1), nums1(n2);
        for (auto& edge : edges1) {
            int u = edge[0], v = edge[1];
            nums2[u].push_back(v);
            nums2[v].push_back(u);
        }

        for (auto& edge : edges2) {
            int u = edge[0], v = edge[1];
            nums1[u].push_back(v);
            nums1[v].push_back(u);
        }

        vector<int> r1(n1, 0), r2(n2, 0);
        for (int i = 0; i < n1; i++) {
            dfs(i, -1, 0, i, k + 1, r1, nums2);
        }


        for (int i = 0; i < n2; i++) {
            dfs(i, -1, 0, i, k, r2, nums1);
        }

        int maxi = *max_element(r2.begin(), r2.end());

        vector<int> res(n1);


        for (int i = 0; i < n1; i++) {
            res[i] = r1[i] + maxi;
        }
        return res;
    }

private:
    void dfs(int temp, int mom, int dist, int root, int maxi, vector<int>& res, vector<vector<int>>& nums) {

        if (dist >= maxi) {
            return;
        }

        res[root]++;
        for (int adj : nums[temp]) {
            if (adj != mom) {
                dfs(adj, temp, dist + 1, root, maxi, res, nums);
            }
        }
    }
};
