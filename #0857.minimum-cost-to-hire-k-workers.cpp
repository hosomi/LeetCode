class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        vector<array<double, 2>> arr;
        for (int i = 0; i < quality.size(); ++i) {
            arr.push_back({(double)(wage[i]) / quality[i],
                (double)quality[i]});
        }

        std::sort(arr.begin(), arr.end());

        double result = DBL_MAX;
        double sum = 0;
        priority_queue<int> pq;
        for (auto ar : arr) {
            sum += ar[1];
            pq.push(ar[1]);
            if (pq.size() > k) {
                sum -= pq.top(), pq.pop();
            }

            double captainsRatio = ar[0];
            if (pq.size() == k) {
                result = std::min(result, sum * captainsRatio);
            }
        }
        return result;
    }
};
