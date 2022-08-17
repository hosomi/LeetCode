class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        // For convenience, the full table for the 26 letters of the English alphabet is given below:
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....",
                          "..",".---","-.-",".-..","--","-.","---",".--.",
                          "--.-",".-.","...","-","..-","...-",".--","-..-",
                          "-.--","--.."};
        int size = words.size();
        std::set<string> set;
        for (int i = 0; i < size; i++) {
            int colSize = words[i].size();
            string s;
            for (int j = 0; j < colSize; j++) {
                s += morse[(int)(words[i][j] - 'a')];
            }
            set.insert(s);
        }
        return set.size();
    }
};
