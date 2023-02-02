class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        map <char,int> m;
        int size = order.size();
        for (int i = 0; i < size; i++) {
            m[order[i]] = i;
        }

        size = words.size();
        for (int i = 0; i < size -1; i++) {
            for (int j = 0; j < std::max(
                words[i].size(), words[i + 1].size()); j++) {
                if ( j >= words[i].size()) {
                    break;
                }

                if (j >= words[i+1].size()) {
                    return false;
                }

                if (m[words[i][j]] > m[words[i+1][j]]) {
                    return false;
                }

                if (m[words[i][j]] < m[words[i+1][j]]) {
                    break;
                }
            }
        }
        return true;
    }
};
