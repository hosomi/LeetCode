class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        map<int, int> sum1, sum2;
        for(int i : nums1) {
            for(int j : nums2) {
                sum1[i + j] += 1;
            }
        }

        for(int i : nums3){
            for(int j : nums4){
                sum2[i + j] += 1;
            }
        }

        int result = 0;
        for (auto i = sum1.begin(); i != sum1.end(); i++) {
            auto j = sum2.find(-i->first);
            if (j != sum2.end()) {
                result += (i->second * j->second);
            }
        }
        return result;
    }
};
