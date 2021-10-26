class Solution {
public:
    bool isValidSerialization(string preorder) {

        int size = preorder.size();
        int i = 0;
        int j = 1;
        while (i < size) {
            if (j == 0) {
                return false;
            }
            
            if (preorder[i] == ',') {
                i ++ ;
            } else if(preorder[i] == '#') {
                j --;
                i ++ ;
            } else {
                while (i < size && preorder[i]!=',') {
                    i ++ ;
                }
                j ++;
            }
        }
        return j == 0;
    }
};
