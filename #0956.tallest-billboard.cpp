class Solution {
public:
    int tallestBillboard(vector<int>& rods) {

        int rods_size = rods.size();
        int sum = 0;
        int ret = 0;
        map<int,int> result;
        map<int,int> pre;
        result.insert(make_pair(0,0));
        for(const auto& num:rods) {
            pre = result;
            for(const auto& tmpmap:pre) {
                int tmp = tmpmap.first+num,tmpsub = tmpmap.first - num;
                if (pre.find(tmp) == pre.end()) {
                    result[tmp] = 0;
                }
                result[tmp] = max(result[tmp],tmpmap.second + num);

                if (pre.find(tmpsub) == pre.end()) {
                    result[tmpsub] = 0;
                }
                result[tmpsub] = max(result[tmpsub],tmpmap.second);
            }
        }
        return result[0];
    }
};
