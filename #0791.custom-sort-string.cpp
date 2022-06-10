class Solution {
public:
    string customSortString(string order, string s) {

        int size = s.size();
        map<char, int> m;
        for (int i = 0; i != size; i++) {
            m[s[i]] += 1;
        }
        
        size = order.size();
        string result = "";
        for (int i = 0; i != size; i++) {
            for (int j = 0; j != m[order[i]]; j++) {
                result += order[i];
            }
            m[order[i]] = 0;
        }

        for (auto it = m.begin(); it != m.end(); it++) {
            for (int j = 0; j != it -> second; j++) {
                result += it->first;
            }
        }
        return result;
    }
};
