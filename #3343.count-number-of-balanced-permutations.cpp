class Solution {
public:
    int countBalancedPermutations(string num) {

        int dp[11][41][41][401];
        const int mod = 1e9 + 7;
        for (int i = 10; i >= 0; --i) {
            for (int j = 0; j < 41; ++j) {
                for (int k = 0; k < 41; ++k) {
                    for (int z = 0; z < 401; ++z) {
                        dp[i][j][k][z] = 0;
                    }
                }
            }
        }

        vector<int> cnt(10, 0);
        int total_sum = 0;
        for (int i = 0; i < num.size(); ++i) {
            ++cnt[num[i] - '0'];
            total_sum += (num[i] - '0');
        }

        if (total_sum & 1) {
            return 0;
        }

        cout << "total_sum: " << total_sum << "\n";
        int all_cnt = num.size();
        vector<vector<int> > cc(all_cnt + 1, vector<int>(all_cnt + 1, 0));
        for (int i = 0; i <= all_cnt; ++i) {
            for (int j = 0; j <= all_cnt; ++j) {
                if (i > 0 && j == 0) {
                    cc[i][j] = 1;
                }

                if (i == j) {
                    cc[i][j] = 1;
                }

                if (i + 1 <= all_cnt) {
                    cc[i + 1][j] += cc[i][j];
                    cc[i + 1][j] %= mod;
                }

                if (i + 1 <= all_cnt && j + 1 <= all_cnt) {
                    cc[i + 1][j + 1] += cc[i][j];
                    cc[i + 1][j + 1] %= mod;
                }
            }
        }

        int even = (num.size() + 1) / 2;
        int odd = num.size() - even;
        int cur_sum = 0;
        for (int i = 10; i > 0; --i) {
            if (i < 10) {
                cur_sum += cnt[i] * i;
            }

            for (int j = 0; j < 41; ++j) {
                for (int k = 0; k < 41; ++k) {
                    if (j > even || k > odd) {
                        break;
                    }

                    for (int z = 0; z < 401; ++z) {
                        int val = dp[i][j][k][z];
                        if (i == 10 && j == 0 && k == 0 && z == 0) {
                            val = 1;
                        } else if(i == 10) {
                            break;
                        }

                        if (val == 0) {
                            continue;
                        }

                        for (int x = 0; x <= cnt[i - 1]; ++x) {
                            int add = (1LL * cc[even - j][x] * cc[odd - k][cnt[i - 1] - x] % mod) * val % mod;
                            int cur_value = z + x * (i - 1);
                            if (cur_value > total_sum / 2) {
                                break;
                            }

                            if (cur_sum - z + (cnt[i - 1] - x) * (i - 1) > total_sum / 2) {
                                continue;
                            }

                            if (j + x >= 41) {
                                break;
                            }

                            if (k + cnt[i - 1] - x >= 41) {
                                continue;
                            }
                            
                            dp[i - 1][j + x][k + cnt[i - 1] - x][cur_value] += add;
                            dp[i - 1][j + x][k + cnt[i - 1] - x][cur_value] %= mod;
                        }
                    }
                }
            }
        }
        return dp[0][even][odd][total_sum / 2];
    }
};
