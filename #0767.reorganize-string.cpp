class Solution {
public:
    string reorganizeString(string s) {
        
        int size = s.size();
        int map[26] = {0};
        for (int i = 0 ; i < size; i++) {
            map[s[i]-'a']++;
        }

        int maxmap = -1;
        int maxchar = '#';
        for (int i = 0; i < 26; i++) {
            if (map[i] > maxmap) {
                maxmap = map[i];
                maxchar = i + 'a';
            }
        }

        if (maxmap > (size + 1) / 2) {
            return "";
        }

        int index = 0;
        while (index < size && maxmap > 0) {
            s[index] = maxchar;
            index = index + 2;
            maxmap--;
        }

        map[maxchar -'a'] = 0;
        for (int i = 0; i < 26; i++) {
            while (map[i] > 0) {
                index = (index >= size) ? 1 : index;
                s[index] = i + 'a';
                index = index + 2;
                map[i]--;
            }
        }
        return s;
    }
};
