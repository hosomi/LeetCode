class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        unordered_map<string, int> um;
        s1 = s1 + " " + s2;
        stringstream ss(s1);
        string s;
        while (ss >> s) {
            um[s]++;
        }
        vector<string> result;
        auto it = um.begin();
        for (it; it != um.end(); it++) {
            if (it->second == 1) {
                result.push_back(it->first);
            }
        }
        return result;
    }
};
