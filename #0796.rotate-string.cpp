class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int a = s.size();
        if (a == 0) {
            return true;
        }

        int b = goal.size();
        if (a != b) {
            return false;
        }
        
        vector<int> v;
        for (int i = 0; i < a; i++) {
            if(s[i] == goal[0]){
                v.push_back(i);
            }
        }
        
        for (int start : v) {
            bool isRotate = true;
            for(int i = 0; i < a; i++){
                if (s[(start + i) % a] != goal[i]) {
                    isRotate = false;
                    break;
                }
            }

            if (isRotate) {
                return true;
            }
        }
        
        return false;
    }
};
