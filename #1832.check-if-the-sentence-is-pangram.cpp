class Solution {
public:
    bool checkIfPangram(string sentence) {

        int size = sentence.size();
        set<char> s;
        for (int i = 0; i < size; i++) {
           s.insert(sentence[i]); 
        }
        return s.size() == 26;
    }
};
