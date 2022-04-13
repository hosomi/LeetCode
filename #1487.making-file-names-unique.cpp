class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        
        int size = names.size();
        unordered_set<string> s;
        unordered_map<string,int> m;
        vector<string> result(names.size());
        for (int i = 0; i < size; ++i) {
            if (s.insert(names[i]).second) {
                result[i] = names[i];
            } else  {
                int k = m[names[i]];
                bool isFound = false;
                while (!isFound) {
                    string x = names[i]+'('+to_string(++k) + ')';
                    if(s.insert(x).second) {
                        result[i] = x;
                        m[names[i]] = k;
                        isFound = true;
                    }
                }
            }
        }
        return result;
    }
};
