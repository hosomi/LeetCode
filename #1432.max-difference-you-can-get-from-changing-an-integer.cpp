class Solution {
public:
    int maxDiff(int num) {

        string s=to_string(num);
        int a = -1e8;
        int b = 1e8;
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                int x = i;
                int y = j;
                string temp=s;
                for (auto &it:temp){
                    if (it - '0' == x) {
                        it = y + '0';
                    }
                }

                if (temp[0] == '0') {
                    continue;
                }

                a = max(a, stoi(temp));
                b = min(b, stoi(temp));
            }
        }

        cout << a << " " << b;
        return a - b;
    }
};
