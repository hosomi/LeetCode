class Solution {
public:
    string orderlyQueue(string s, int k) {

        if (k > 1) {
            std::sort(s.begin(), s.end());
            return s;
        }
        
        int size = s.size();
        string result = s;
        for (int i = 0; i < size; i++) {
            result = std::min(result, s.substr(i) + s.substr(0, i));
        }
        return result;
    }
};
