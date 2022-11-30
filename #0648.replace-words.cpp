class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        unordered_set<string> s;
        for (string &d : dictionary) {
            s.insert(d);
        }

        int size = sentence.size();
        string result;
        string cur;
        for (int i = 0, j; i <= size; i++) {
            if (i < size && !isspace(sentence[i])) {
                cur += sentence[i];
                continue;
            }
            
            string x;
            for (j = 0; j < cur.length(); j++) {
                x += cur[j];
                if (s.find(x) != s.end()) {
                    result += x + ' ';
                    break;
                }
            }

            if (j == cur.length()) {
                result += x + ' ';
            }
            cur.clear();
        }
        return result.substr(0, result.length() - 1);
    }
};
