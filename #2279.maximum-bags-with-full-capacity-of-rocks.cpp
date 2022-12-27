class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        vector<int>v;
        int size = capacity.size();
        for (int i = 0; i < size; i++) {
            v.push_back(capacity[i]-rocks[i]);
        }
        
        std::sort(begin(v), end(v));
        int i = 0;
        for (;i < size && additionalRocks >= v[i];i++) {
            additionalRocks -= v[i];
        }
        return i;
    }
};
