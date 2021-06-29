class Solution {
public:
    int compareVersion(string version1, string version2) {

        int v1size = version1.size();
        int v2size = version2.size();
        int i = 0;
        int j = 0;
        int v1 = 0;
        int v2 = 0;
        while (i < v1size || j < v2size) {
            while (i < v1size && version1[i] != '.') {
                v1 = v1 * 10 + version1[i] - '0';
                i++;
            }

            while(j < v2size && version2[j] != '.') {
                v2 = v2 * 10 + version2[j] - '0';
                j++;
            }

            if (v1 > v2) {
                return 1;
            }
            
            if (v1 < v2) {
                return -1;
            }

            v1 = 0;
            v2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};
