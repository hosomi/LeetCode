class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        unordered_map<int, int> counter;
        for (int barcode : barcodes) {
            counter[barcode]++;
        }
        
        priority_queue<pair<int, int>,
            vector<pair<int, int>>, less<pair<int, int>>
        > pq;
        for (auto it = counter.begin(); it != counter.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }
        
        vector<int> result;
        while (pq.size() >= 2) {
            pair<int, int> p1 = pq.top(); pq.pop();
            pair<int, int> p2 = pq.top(); pq.pop();
            result.push_back(p1.second);
            result.push_back(p2.second);
            p1.first--;
            p2.first--;
            
            if (p1.first > 0) {
                pq.push(p1);
            }
            
            if (p2.first > 0) {
                pq.push(p2);
            }
        }
        
        if (pq.size() > 0) {
            pair<int, int> p = pq.top(); pq.pop();
            result.push_back(p.second);
        }
        
        return result;
    }
};
