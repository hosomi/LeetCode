class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        oldc = image[sr][sc];
        newc = newColor;

        if (oldc != newc) {
            floodFill(image, sr, sc);
        }
        return image;
    }
    
private:
    int oldc;
    int newc;

    void floodFill(vector<vector<int>>& image, int sr, int sc) {

        if (image[sr][sc] == oldc) {
            image[sr][sc] = newc;
            if(sr > 0) {
                floodFill(image, sr - 1, sc);
            }
            if (sc > 0) {
                floodFill(image, sr, sc - 1);
            }
            if (sr < image.size() - 1) {
                floodFill(image, sr + 1, sc);
            }
            if (sc < image[0].size() - 1) {
                floodFill(image, sr, sc + 1);
            }
        }
    }
};
