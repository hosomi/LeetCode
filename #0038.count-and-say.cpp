class Solution {
public:
    string countAndSay(int n) {

        string result = "1";
        string work = "";
        int size;
        int index;
        char c;
        for (int i = 2; i <= n; i++) {
            work = "";
            index = 1;
            c = result[0];
            size = result.size();
            for (int j = 1; j < size; j++) {
                if (result[j] == c) {
                    index++;
                } else {
                    work += to_string(index);
                    work.push_back(c);
                    index = 1;
                    c = result[j];
                }
            }
            work += to_string(index);
            work.push_back(c);
            result = work;
        }
        return result;
    }
};
