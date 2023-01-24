class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int size = board.size();
        int xy = size * size;
        vector<int> vec(xy + 1, 0);
        int k = 0;
        int l = 1;
        for (int i = size - 1; i >= 0; i--) {
            for (int j = 0; j < size; j++) {
                vec[l++] = k % 2 == 0 ?
                    board[i][j] : board[i][size - 1 - j];
            }
            k++;
        }

        for (int i = 1; i <= size * size; i++) {
            cout << "i:" << i << " " << vec[i] << endl;
        }

        int min = INT_MAX;
        queue<pair<int,int>> q;
        q.push({1,0});
        vector<bool> visited(xy + 1, false);
        while (!q.empty()) {
            pair<int,int> ti=q.front();
            q.pop();
            int ti1 = ti.first;
            int ti2 = ti.second;
            cout<<"ti1: "<<ti1<<endl;
            if (ti1 == xy) {
                min = std::min(min, ti2);
                continue;
            }
            
            for (int j = 1; j <= 6; j++) {
                int x=ti1+j;
                cout<<"x: "<<x<<endl; 
                int r=0;
                if ( x <= xy) {
                    r = vec[x];
                } else {
                    continue;
                }

                if (r == -1) {
                    r=x;
                }

                if (r <= xy && !visited[r]) {
                    cout << "pushed r:" << r << endl;
                    visited[r]=true;
                    q.push({r,ti2+1});
                }
            }
        }

        if (min == INT_MAX) {
            return -1;
        }
        return min; 
    }
};
