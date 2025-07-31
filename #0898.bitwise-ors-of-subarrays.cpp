class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {

        int n = arr.size();
        unordered_set<int> st;
        unordered_set<int> preSet;
        preSet.insert(arr[0]);
        for (int i = 0; i < n; i++) {
            unordered_set<int> newPreSet;
            newPreSet.insert(arr[i]);
            for (auto it : preSet) {
                newPreSet.insert(it|arr[i]);
            }

            for (auto it : newPreSet) {
                st.insert(it);
            }
            preSet=newPreSet;
        }
        return st.size(); 
    }
};
