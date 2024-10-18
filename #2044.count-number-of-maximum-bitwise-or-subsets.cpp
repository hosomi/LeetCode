class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {

        map<int, int> m;
        int mx = 0;
        for (int num: nums) {
            map<int, int> tems(m);
            for(auto tem: tems){
                m[num | tem.first] += tem.second;
            }
            m[num] += 1;
            mx = mx | num;
        }
        return m[mx];
    }
};
