class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        if (name[0] != typed[0]) {
            return false;
        }

        int n = name.size();
        int m = typed.size();
        int i = 0;
        int j = 0;
        while (i < n || j < m) {
            if (name[i] == typed[j]) {
                i++;
            } else if (typed[j] != typed[j-1]) {
                return false;
            }
            j++;
        }
        return true;
    }
};
