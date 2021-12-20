class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        int distinct = INT_MAX;
        std::sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        for (int i = 0; i < arr.size() - 1; i++) {
            if(arr[i+1] - arr[i] < distinct){
                distinct = arr[i+1] - arr[i];
                result.clear();
                result.push_back({arr[i], arr[i+1]});
            } else if(arr[i+1] - arr[i] == distinct) {
                result.push_back({arr[i], arr[i+1]});
            }
        }
        return result;
    }
};
