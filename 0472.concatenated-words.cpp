class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        unordered_set<string> dict(words.begin(), words.end());
        unordered_map<string, bool> concat;
        vector<string> result;
        for (auto word : words) {
            if (concatenatePossible(word, dict, concat)) {
                result.push_back(word);
            }
        }
        return result;
    }

private:
    bool concatenatePossible(string word,
        unordered_set<string>& dict,
        unordered_map<string, bool> &concat){
        
        if (concat.find(word)!= concat.end()) {
            return concat[word];
        }

        for (int i=1; i<word.size(); ++i) {
            string substring = word.substr(0, i);
            if (dict.count(substring)) {
                string restSubstring = word.substr(i);
                if (dict.count(restSubstring)
                    || concatenatePossible(restSubstring, dict, concat)) {
                    concat.insert({word, true});
                    return true;
                }
            }
        }
        concat.insert({word, false});
        return false;
    }
};
