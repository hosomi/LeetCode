class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int size = profits.size();
        vector<pair<int,int>> arr;
        for (int i = 0; i < size; i++) {
            arr.push_back({capital[i], profits[i]});
        }

        std::sort(arr.begin(),arr.end());
        priority_queue<int>pq;
        for(int i = 0; i < size && k; i++) {
            if (w >= arr[i].first && k) {
                pq.push(arr[i].second);
            } else {
                if (pq.empty()) {
                    return w;
                }
                w += pq.top();
                pq.pop();
                k--;
                i--;
            }
        }
        while (k-- && !pq.empty()) {
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
