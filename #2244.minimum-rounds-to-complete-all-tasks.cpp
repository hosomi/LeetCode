class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int> m;
        for(auto it : tasks) {
            m[it]++;
        }
    
        int result = 0;
        for (auto it : m) {
            if (it.second < 2) {
                return -1;
            }
            
            if (it.second >= 3) {
                int div = it.second / 3;
                if (it.second % 3 != 0) {
                    div++;
                }
                result += div;
            }else{
                int div = it.second / 2;
                if (it.second % 2 != 0) {
                    div++;
                }
                result += div;
            }
        }
        return result;
    }
};
