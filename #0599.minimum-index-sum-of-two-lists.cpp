class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {

        size_t size = list1.size();
        if (size < list2.size()) {
            return findRestaurant(list2, list1);
        }
        
        unordered_map<string, int> map2;
        int i2 = -1;
        for (auto& s : list2) {
            map2[s] = ++i2;
        }
        
        vector<string> result;
        for (size_t i = 0, minSum = INT_MAX; i < std::min(minSum + 1, size); ++i) {
            int sum = map2.count(list1[i]) ? i + map2[list1[i]] : INT_MAX;
            if (sum < minSum) {
                result = {list1[i]}, minSum  = sum;
            } else if (sum == minSum) {
                result.push_back(list1[i]);
            }
        }
        return result;   
    }
};
