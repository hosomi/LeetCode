class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<int, int> mp1;
        for (int i = 0; i < arr1.size(); i++) {
            int a = arr1[i];
            while (a) {
                mp1[a]++;
                a /= 10;
            }
        }
        
        unordered_map<int, int> mp2;
        for (int i = 0; i < arr2.size(); i++) {
            int a = arr2[i];
            while (a) {
                mp2[a]++;
                a /= 10;
            }
        }
        
        int result = 0;
        for (auto &[i, j] : mp1) {
            if (mp2.find(i) != mp2.end()) {
                string s = to_string(i);
                result = std::max(result, (int)s.size());
            }
        }
        
        return result;
    }
};
