class Solution {
public:
    string smallestNumber(string pattern) {

		int n = pattern.length();
		string ans = "";
		for (char c = '1'; c <= n + 1 + '0'; c++) {
            ans += c;
        }

		vector<int> temp(n, 0);
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			while (i + cnt < n && pattern[i + cnt] == 'D') {
				cnt++;
            }
			temp[i] = cnt;
		}

		for (int i = n - 1; i > 0; i--) {
			if (temp[i] < temp[i - 1]) {
				temp[i] = 0;
            }
        }

		for (int i = 0; i < n; i++) {
			int l = i;
            int r = i + temp[i];
			while(l<r) {
				swap(ans[l], ans[r]);
                l++;
                r--;
            }
		}
		return ans;
    }
};
