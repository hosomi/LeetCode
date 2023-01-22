class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        int count[k + 1];
        memset(count, 0, sizeof(count));
        set<pair<int, int>> free;
        map<int, bool> m;
        for (int i = 0; i < k; i++) {
            m.insert({i,1});
        }
        
        for (int i = 0; i < arrival.size(); i++) {
            while (free.size() > 0 && (*free.begin()).first <= arrival[i]) {
                m.insert({(*free.begin()).second, 1}), free.erase(free.begin());
            }
            
            auto it = m.lower_bound(i % k);
            if (it == m.end() && m.size() > 0) {
                it = m.begin();
            }

            if (it != m.end()) {
                count[(*it).first]++;
                free.insert({arrival[i] + load[i], (*it).first});
                m.erase(it);
            }
        }
                           
        int max = 0;
        for (int i = 0; i < k; i++) {
             max = std::max(max, count[i]);
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            if (count[i] == max) {
                result.push_back(i);
            }
        }
        return result;
    }
};
