class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {

        int size = words.size();
        unordered_map<string, int> hash;
        vector<vector<int>> result;
        for (int i = 0; i < size; i++) {
            hash[words[i]] = i;
        }

        for (int i = 0; i < size; i++) {
            std::reverse(words[i].begin(), words[i].end());
            int col = words[i].size();
            for (int j = 0; j <= col; j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if (hash.count(left) && isPalin(right) && hash[left] != i && col > j) {
                    result.push_back(vector<int>{hash[left], i});
                }
                if (hash.count(right) && isPalin(left) && hash[right] != i) {
                    result.push_back(vector<int>{i, hash[right]});
                }
            }
        }
        return result;
    }

private:
    bool isPalin(string& str) {

        for (int i = 0; i < str.size() / 2; i++) {
            if (str[i] != str[str.size() -i -1]) {
                return false;
            }
        }
        return true;
    }
};
