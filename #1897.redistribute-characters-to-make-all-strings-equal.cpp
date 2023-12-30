class Solution {
public:
    bool makeEqual(vector<string>& words) {

        unordered_map<char, int> um;
        for (auto w : words) {
            for (int i = 0; i < w.size(); i++) {
                um[w[i]]++;
            }        
        }
        for (auto m : um) {
            if (m.second % words.size() != 0) {
                return false;
            }
        }
        return true;
    }
};
