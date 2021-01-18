class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        
        vector<int> vresult;
        int size = A.size();
        vector<int> vindex(size);
        iota(vindex.begin(), vindex.end(), 1);
        sort(vindex.begin(), vindex.end(), 
             [&A](const int i, const int j) { 
                 return A[i-1] > A[j-1];
             }
        );

        for (int index : vindex) {
            for (int result : vresult) {
                if (index <= result) {
                    index = result + 1 - index; // 古い位置 + 新しい位置 = 反転したベクトルのサイズ + 1
                }
            }
            vresult.push_back(index);
            vresult.push_back(size--);
        }
        
        return vresult;
    }
};
