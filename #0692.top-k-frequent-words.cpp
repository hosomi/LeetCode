class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> m;
        auto comp = [&m](const string& l, const string& r) {
            return (m[l] == m[r]) ? (l > r) : 
                (m[l] < m[r]);
        };
        
        priority_queue<string, vector<string>, decltype(comp)> pq(comp);
        for (string& word : words) {
            m[word]++;
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            pq.push(it->first);
        }
        
        vector<string> result;
        while(k-- > 0){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};
