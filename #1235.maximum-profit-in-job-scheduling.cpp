class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int size = startTime.size();
        vector<array<int, 3>> ar;
        for (int i = 0; i < size; ++i) {
            ar.push_back({startTime[i], endTime[i], profit[i]});
        }

        std::sort(ar.begin(), ar.end());
        
        map<int,int> m1, m2;
        int result = -1;
        for (int i = size - 1; i >= 0; --i) {
            auto it = m1.lower_bound(ar[i][1]);
            if (it != m1.end()) {
                m2[ar[i][0]] = std::max({result, (*it).second + ar[i][2]});
            } else {
                m2[ar[i][0]] = std::max({ar[i][2], result, m2[ar[i][0]]});
            }
            
            m1[ar[i][0]] = std::max(m1[ar[i][0]], m2[ar[i][0]]);
            result = std::max(result, m2[ar[i][0]]);
        }
        return result;
    }
};
