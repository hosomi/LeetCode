class Solution {
public:
    vector<int> findArray(vector<int>& pref) {

        int size = pref.size();
        vector<int> results(size);
        results[0] = pref[0];
        for (int i = 1; i < size; i++) {
            results[i] = pref[i-1]^pref[i];
        }
        return results;
    }
};
