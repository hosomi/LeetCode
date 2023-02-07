class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        map<int,int> m;
        int index = 0;
        int size = fruits.size();
        int result = 0;
        for (int i = 0; i < size; i++) {            
            if (m.size() <= 2) { 
                m[fruits[i]]++;
            }
            
            while (m.size() > 2 && index < size) {
                m[fruits[index]]--;
                if (!m[fruits[index]]) {
                    m.erase(fruits[index]);
                }
                index++;
            }
            result = std::max(result, i - index + 1);
        }
        return result;
    }
};
