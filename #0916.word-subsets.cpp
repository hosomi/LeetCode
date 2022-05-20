class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<int> order(26, 0);
        for (auto w : words2) {
            vector<int>v(26, 0);
            for (auto y : w) {
                v[y-'a']++;
                order[y-'a'] = std::max(order[y-'a'], v[y-'a']); 
            }
        }

        vector<string> result;
        for (auto w : words1) {
            vector<int>v(26, 0);
            for (auto y : w) {
                v[y-'a'] ++;
            }

            bool isSubset = true;
            for(int i = 0 ; i < 26 ; i++) {
                if (order[i] > v[i]) {
                    isSubset = false;
                    break;
                }
            }

            if (isSubset) {
                result.push_back(w);
            }
        }
        return result;
    }
};
