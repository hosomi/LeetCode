class Solution {
public:
    double soupServings(int n) {
        
        if (n >= 5000) {
            return 1.0;
        }
        map<pair<int, int>, double>mp;
        return soupServings(n, n, mp);
    }

private:
    double soupServings(int a,int b,
        map<pair<int,int>,double>&mp) {
        
        if (a <= 0 && b<=0) {
            return 0.5;
        }

        if (a <= 0) {
            return 1;
        }

        if (b <= 0) {
            return 0;
        }

        if (mp.count({a, b})) {
            return mp[{a, b}];
        }

        double result = 0;
        result += soupServings(a-100,b,mp);
        result += soupServings(a-75,b-25,mp);
        result += soupServings(a-50,b-50,mp);
        result += soupServings(a-25,b-75,mp);
        return mp[{a, b}] = (double)result / (double)4;
    }
};
