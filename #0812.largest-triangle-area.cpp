class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
      
      int size = points.size();
      int result = 0;
      for (int i = 0; i != size; i++) {
          for (int j = i + 1; j != size; j++) {
              for (int k = j + 1; k != size; k++) {
                  result = std::max(result, abs(
                      (points[j][0] - points[i][0]) 
                      * (points[k][1] - points[i][1])
                      - (points[k][0] - points[i][0]) 
                      * (points[j][1] - points[i][1])
                  ));
              }
          }
      }    
      return double(result) / 2;
    }
};
