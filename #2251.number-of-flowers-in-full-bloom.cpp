class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        vector<int> start;
        vector<int> end;
        for (vector<int> &f : flowers) {
            start.push_back(f[0]);
            end.push_back(f[1]);
        }

        std::sort(start.begin(), start.end());
        std::sort(end.begin(), end.end());
        
        vector<int> results;
        for (int &p : people) {
            auto itu = upper_bound(start.begin(), start.end(), p);
            auto itl = lower_bound(end.begin(), end.end(), p);
            int u = itu - start.begin();
            int l = itl - end.begin();
            results.push_back(u - l);
        }
        return results;
    }
};
