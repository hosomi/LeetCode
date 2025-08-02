class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        
        map<int, int> mp;
        for (int i = 0; i < basket1.size(); ++i) {
            mp[basket1[i]]++; mp[basket2[i]]--;
        }

        int mn = mp.begin()->first;
        int count = 0;
        for (auto m : mp) {
            if (m.second % 2) {
                return -1;
            }
            count += max(0, m.second/2);
        }

        long long ans = 0; 
        for (auto m : mp) {
            if (m.second && count > 0) {
                long long t1 = min(count , abs(m.second/2));
                long long t2 = min( 2 * mn , m.first);
                ans += t1 * t2;
                count -= abs(m.second/2);
            }
        }
        return ans;    
    }
};
