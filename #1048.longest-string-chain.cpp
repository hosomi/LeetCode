class Solution {
public:
    int longestStrChain(vector<string>& words) {

        std::sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        });

        unordered_map<string, int> longest;
        int result = 1;
        for (string& word : words) {
            for (int i = 0; i < word.size(); i++) {
                longest[word] = std::max(
                    longest[word],
                    longest[word.substr(0, i) + word.substr(i + 1)] + 1
                );
            }
            result = std::max(result, longest[word]);
        }
        return result;
    }
};
