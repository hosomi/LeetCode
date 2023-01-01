class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {


        map<char, int> count;
        for (char c : licensePlate) {
            if (!isalpha(c)) {
                continue;
            }
    
            c = tolower(c);
            if (count.find(c) == count.end()) {
                count[c] = 1; 
            } else {
                count[c] += 1;
            }
        }
 
        string result = "";
        for (string word : words) {
            map<char, int> tmp = count;
            for (char c : word) {
                if (tmp.find(c) != tmp.end()) {
                    tmp[c]--;
                    if (tmp[c] == 0) {
                        tmp.erase(c);
                    }
                }
            }

            if (tmp.size() == 0) {
                if (result == "") {
                    result = word;
                } else if (word.size() < result.size()) {
                    result = word;
                }
            }
        }
        return result;
    }
};
