class Solution {
public:
    bool isScramble(string s1, string s2) {

        if (s1.size() != s2.size()) {
            return false;
        }
        return isScrambled(s1,s2);
    }

private:
    unordered_map<string,bool> um;

    bool isScrambled(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        
        int size = s1.size();
        if (s1 == s2 or size == 0) {
            return true;
        }

        string contain = s1 + " " + s2;
        if (um.find(contain) != um.end()) {
            return um[contain];
        }

        bool result = false;
        for (int i=1; i < size; i++) {
            if (isScrambled(s1.substr(0, i),s2.substr(size - i, i)) 
                and isScrambled(s1.substr(i, size - i), s2.substr(0, size - i))) {
                result |= true;
                break;
            }

            if (isScrambled(s1.substr(0, i), s2.substr(0, i))
                and isScrambled(s1.substr(i, size - i), s2.substr(i, size - i))) {
                result |= true;
                break;
            }
        }
        um[contain] = result;
        return result;
    }
};
