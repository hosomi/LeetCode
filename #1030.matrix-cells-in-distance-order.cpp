class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {

        vector<pair<vector<int>, int>> distances;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                distances.push_back(
                    std::make_pair(
                        vector<int>{i, j}, std::abs(i - rCenter) + std::abs(j - cCenter)
                    )
                );
            }
        }
        
        std::sort(distances.begin(), distances.end(), comparator);
        vector<pair<vector<int>, int>>::iterator it;
        vector<vector<int>> result;
        for (it = distances.begin(); it != distances.end(); it++) {
            result.push_back(it->first);
        }

        return result;
    }
    
private:
    static bool comparator(pair<vector<int>, int>& left, pair<vector<int>, int>& right){
        return left.second < right.second;
    };
};
