class Solution {
public:
    int longestPalindrome(vector<string>& words) {

        map<string,int> m;
        int size = words.size();
        int count = 0;
        int flag = 0;
        string s;
        for (int i = 0; i < size; i++) {
            s = words[i];
            swap(s[1], s[0]);

            if (s == words[i]) {
                flag = m[s] == 0 ? flag + 1 : flag -1;
            }

            if (m[s] == 0) {
                m[words[i]]++;
            } else {
                m[s]--;
                count += 4;
            }
        }

        if (flag > 0) {
            count += 2;
        }
        return count;
    }
};
