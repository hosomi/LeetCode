class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        vector<map<char, int>> counts;
        for (string w : words) {
            map<char, int> count;
            for (char c : w) {
                if (count.find(c)==count.end()) {
                    count[c] = 1;
                } else {
                    count[c] += 1;
                }
            }
            counts.push_back(count);
        }
        
        int size = counts.size();
        map<char, int> index = counts[0];
        for(int i = 1; i < size; i++) {
            for (map<char, int>::iterator it = index.begin(); it != index.end(); it++) {
                char c = it->first;
                if (counts[i].find(c) == counts[i].end()) {
                    index[c] = 0;
                } else {
                    index[c] = std::min(index[c], counts[i][c]);
                }
            }
        }
        
        vector<string> result;
        for (map<char, int>::iterator it = index.begin(); it != index.end(); it++) {
            while (it->second>0) {
                result.push_back(string(1,it->first));
                it->second-=1;
            }
        }
        return result;
    }
};
