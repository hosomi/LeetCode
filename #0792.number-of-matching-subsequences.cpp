class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int result = 0;
        for(string word: words) {
            if (isMatching(s, word)) {
                result++;
            }
        }
        return result;
    }

private:
    bool isMatching(const string &s, const string &word) {

        std::size_t idx = 0;    
        for (char c: word) {
            idx = s.find_first_of(c, idx);
            if (idx++ == string::npos) {
                return false;
            }
        }
        return true;
    }
};
