class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        
        int size = arr.size();
        map<int,int> m;
        int counter = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == 0) {
                counter++;
            } else{
                m[arr[i]]++;
            }
        }

        if (counter % 2){
            return false;
        }

        while (m.size()) {
            auto begin = m.begin();
            auto end = m.end();
            if (begin->first > 0) {
                end = m.find(begin->first * 2);
            } else {
                if (((-1) * begin->first) % 2) {
                    return false;
                }
                end = m.find(begin->first/2);
            }

            if (end == m.end()) {
                return false;
            }

            if (--end->second == 0) {
                m.erase(end);
            }

            if (--begin->second == 0) {
                m.erase(begin);
            }
        }
        return true;
    }
};
