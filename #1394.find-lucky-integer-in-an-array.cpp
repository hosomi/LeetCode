class Solution {
public:
    int findLucky(vector<int>& arr) {

        int ans =- 1;
        map<int, int> a;
        for (int i : arr) {
            a[i]++;
        }

        for (auto i : a) {
            if (i.first == i.second) {
                ans = max(ans,i.first);
            }
        }
        return ans;
    }
};
