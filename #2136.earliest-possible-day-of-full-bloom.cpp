class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {

        int size = plantTime.size();
        vector<pair<int, int>> v; 
        for (int i = 0; i < size; ++i) {
            v.emplace_back(plantTime[i], growTime[i]); 
        }
        
        std::sort(v.begin(), v.end(), [&](auto& left, auto& right) {
            return left.second > right.second;
        }); 
        
        size = v.size();
        int result = 0; 
        for (int i = 0, j = 0; i < size; ++i) {
            j += v[i].first; 
            result = std::max(result, j + v[i].second); 
        }
        return result; 
    }
};
