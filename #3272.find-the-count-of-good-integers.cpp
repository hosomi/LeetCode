class Solution {
public:
    long long countGoodIntegers(int n, int k) {

        int h = (n + 1) / 2;
        long long res{};
        int n1 = pow(10, h - 1);
        int n2 = pow(10, h) - 1;
        unordered_set<string> str;
        for (int i{n1}; i <= n2; ++i) {
            string pre{to_string(i)};
            string suff{pre};
            if (n % 2) {
                suff.pop_back();
            }
            
            std::reverse(suff.begin(), suff.end());
            string nn{pre + suff};
            long long n3{stoll(nn)};
            if (n3 %k != 0) {
                continue;
            }

            std::sort(nn.begin(), nn.end());
            str.insert(nn);
        }

        long long int fn{itr(n)};
        for (auto &nn: str) {
            vector<int> v(10);
            for (auto &c: nn) {
                ++v[c-'0'];                
            }

            long long int res2{fn};
            long long res3{(v[0] == 0) ? 0 : itr(n-1)};
            for (int i{}; i < 10; ++i) {
                if (v[i] == 0) {
                    continue;
                }

                res2 /= (itr(v[i]));
                if (i == 0 && v[0]) {
                    --v[0];
                }
                res3 /= (itr(v[i]));
            }
            res+=(res2 - res3) ;
        }
        return res;
    }

private:
    long long int itr(int n) {

        long long int f{1};
        for(int i{2}; i<=n; ++i) f*=i;
        return f;
    }
};
