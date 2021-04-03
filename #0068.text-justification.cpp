class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> word;
        vector<string> result;
        int wsize = 0;
        int index = 0;
        int size = words.size();
        while (index < size) {
            if (wsize + (word.size() - 1) + (1 + words[index].size()) <= maxWidth) {
                wsize += words[index].size();
                word.push_back(words[index]);
                ++index;
            } else {
                string str = "";
                if (word.size() == 1) {
                    str += word[0];
                    str += string(maxWidth - str.size(), ' ');
                } else {
                    int quot = (maxWidth - wsize) / (word.size() - 1);
                    int mod = (maxWidth - wsize) % (word.size() - 1);
                    
                    for (int i = 0; i < word.size(); ++i) {
                        str += word[i];
                        if (i != word.size() - 1) {
                            str += string(quot + (i < mod), ' ');
                        }
                    }
                }
                result.push_back(str);
                word.clear();
                wsize = 0;
            }
        }

        string work = "";
        for (int i = 0; i < word.size(); ++i) {
            work += word[i];
            if (i != word.size()-1) {
                work += " ";
            }
        }
        work += string(maxWidth - work.size(), ' ');
        result.push_back(work);
        result.back() += string(maxWidth - result.back().size(), ' ');

        return result;
    }
};
