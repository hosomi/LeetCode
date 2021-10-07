class Solution {
public:
    bool isAdditiveNumber(string num) {

        int size = num.size();
        if (size <= 2) {
            return false;
        }

        string s1;
        string s2;
        string s3;
        for (int i = 1; i <= size / 2; i++) {
            s1 = num.substr(0, i);
            for (int j = 1; j <= size / 2; j++) {
                s2 = num.substr(i, j);
                s3 = num.substr(i + j, size - i - j);

                if (dfs(s1, s2, s3)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(string first, string second, string last) {

        if (first[0] == '0'
            && first != "0" || second[0] == '0'
            &&second != "0") {
            return false;
        }

        string addstr = add(first, second);
        if (addstr.size() > last.size()) { 
            return false;
        }

        if (addstr == last) { 
            return true;
        }

        int size = addstr.size();
        if (addstr != last.substr(0, size)) {
            return false;
        }

        first = second;
        second = addstr;
        last = last.substr(size, int(last.size()) - size);
        return dfs(first, second, last);
    }
    
    string add(string str1, string str2) {
        if (str1.size() < str2.size()) swap(str1, str2);
        int size1 = str1.size();
        int size2 = str2.size();
        str2 = string(size1 - size2, '0') + str2;
        int sgn = 0;
        for (int i = size1; i >= 1; i--) {
            int nums = str1[i - 1] - '0' + str2[i - 1] - '0' + sgn;
            str1[i - 1] = nums % 10 + '0';
            sgn = nums / 10;
        }
        if (sgn == 1) {
            str1 = "1" + str1;
        }
        return str1;
    }
};
