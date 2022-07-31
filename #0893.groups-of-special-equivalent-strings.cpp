class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {

        int size = words.size();
        if (size == 0) {
           return 0;
        }
        
        vector<string> groups;
        for (int i = 0; i < size; i++) {
            string s;
            int colSize = words[i].size();

            for (int j = 0; j < colSize; j+=2) {
                s.push_back(words[i][j]);
            }
            
            for (int j = 1; j < colSize; j+=2) {
                s.push_back(words[i][j]);
            }

            int sSize = s.size();
            std::sort(s.begin(), s.begin() + (sSize + 1) / 2);
            std::sort(s.begin() + (sSize + 1) / 2, s.end());
            groups.push_back(s);
        }

        std::sort(groups.begin(), groups.end());
        
        int group = 1;
        for (int i = 1; i < groups.size(); i++) {
            if (groups[i] != groups[i-1]) {
                group++;
            }
        }
        return group;
    }
};
