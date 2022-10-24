class Solution {
public:
    int maxLength(vector<string>& arr) {

        size = arr.size();
        string s;
        maxLength(arr, 0, s);
        return max;
    }

private:
    int size = 0;
    int max = 0;

    void maxLength(vector<string> arr,
                   int start,
                   string &s) {

        if (s.length() > max) {
            max = s.length();
        }

        if (start == size) {
            return;
        }

        for (int i = start; i < size; i++) {
            string temp = s + arr[i];
            bool mask[27] = {false};
            for (char c: s) {
                mask[c-'a'] = true;
            }

            bool unique_chars = true;
            for (char c: arr[i]) {
                if (mask[c-'a']) {
                    unique_chars = false;
                    break;
                }
                mask[c-'a'] = true;
            }

            if (unique_chars) {
                maxLength(arr, i + 1, temp);
            }
        }
    }
};
