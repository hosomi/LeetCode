class Solution {
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> result;
        vector<int> vec;
        vec.push_back(-1);
        partition(s, 0, result, vec);
        return result;
    }

 private:
    void partition(string s, int i, vector<vector<string>> &result, vector<int> &vec) {

        if (i == s.length()) {
            vector<string> v;
            int size = vec.size();
            for(int j = 0; j < size - 1; j++) {
                v.push_back(s.substr(vec[j] + 1, vec[j + 1] - vec[j]));
            }
            result.push_back(v);
            return;
        }
 
        for (int j = i; j < s.length(); j++) {
            if (isPartition(s, i, j)) {
                vec.push_back(j);
                partition(s, j + 1, result, vec);
                vec.pop_back();
            }
        }
    }

    bool isPartition(string &s, int i, int j) {

        while(i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};
