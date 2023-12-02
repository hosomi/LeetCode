class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        map<char, int> m;
        for (int i = 0; i < chars.length(); i++) {
            m[chars[i]]++;
        }

        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            map<int, char> m2;
            for (int j = 0; j < words[i].size(); j++) {
                m2[words[i][j]]++;
            }

            int isLeft = 0;
            for (auto it : m2) {
                if (m[it.first]<it.second) {
                    isLeft = 1;
                    break;
                }
            }

            if (isLeft != 1) {
                result += words[i].size();
            }
        }
        return result;
    }
};
