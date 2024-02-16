class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    
        unordered_map<int,int> m;
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }

        vector<int> v;
        for (auto it : m) {
            v.push_back(it.second);
        }

        std::sort(v.begin(), v.end());

        int i = 0;
        while (k > 0 && i < v.size()) {    
            k -= v[i];
            if (k < 0) {
                break;
            }
            i++;
        }
        return (v.size() - i);
    }
};
