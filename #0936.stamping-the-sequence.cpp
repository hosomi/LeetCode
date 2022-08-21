class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {

        if (stamp == target) {
            return {0};
        }

        int slen = stamp.size();
        int tlen = target.size() - slen + 1;
        int i;
        int j;
        bool tdiff = true;
        bool sdiff;
        vector<int> result;
        while (tdiff) {
            for (i = 0, tdiff = false; i < tlen; i++) {
                for (j = 0, sdiff = false; j < slen; j++) {
                    if (target[i + j] == '*') {
                        continue;
                    } else if (target[i + j] != stamp[j]) {
                        break;
                    } else {
                        sdiff = true;
                    }
                }

                if (j == slen && sdiff) {
                    for (j = i, tdiff = true; j < slen + i; j++) {
                        target[j] = '*';
                    }
                    result.push_back(i);
                }
            }
        }

        int tSize = target.size();
        for (i = 0; i < tSize; i++) {
            if (target[i] != '*') {
                return {};
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
