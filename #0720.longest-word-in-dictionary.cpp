class Solution {
public:
    string longestWord(vector<string>& words) {

        unordered_set<string> set;
        string s;
        std::sort(words.begin(), words.end());
        for (string word : words) {
            int size = word.size();
            if (size == 1 || set.find(word.substr(0, size - 1)) != set.end()) {
                s = size == s.size() ? word < s ?
                    word : s : size > s.size() ? word : s;
                set.insert(word);
            }
        }
        return s;
    }
};
