class Solution {
public:
    int countVowelPermutation(int n) {

		long a = 1;
        long e = 1;
        long i = 1;
        long o = 1;
        long u = 1;
		int mod = 1e9 + 7;
		for (int j = 2; j <= n; j++) {
			long a2 = (e + u + i) % mod;
			long e2 = (a + i) % mod;
			long i2 = (e + o) % mod;
			long o2 = i % mod;
			long u2 = (o + i) % mod;
			a = a2;
			e = e2;
			i = i2;
			o = o2;
			u = u2;
		}
		return (a + e + i + o + u) % mod;
    }
};
