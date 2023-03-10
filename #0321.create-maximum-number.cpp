class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {

        int na = nums1.size();
        int nb = nums2.size();
        vector<int> empty;
        if (na + nb < k) {
            return empty;
        }

        vector<vector<int>> a(na + 1, empty);
        vector<vector<int>> b(nb + 1, empty);
        a[na] = nums1;
        b[nb] = nums2;
        int f = 0;
        for (int i = na - 1; i >= 0; i--) {
            a[i] = a[i + 1];
            f = 0;
            for (int j = 0; j < i; j++) {
                if (a[i][j] < a[i][j + 1]) {
                    a[i].erase(a[i].begin() + j);
                    f = 1;
                    break;
                }
            }
            if (f == 0) {
                a[i].erase(a[i].begin() + i);
            }
        }

        for (int i = nb - 1; i >= 0; i--) {
            b[i] = b[i + 1];
            f = 0;
            for (int j = 0; j < i; j++) {
                if (b[i][j] < b[i][j + 1]) {
                    b[i].erase(b[i].begin() + j);
                    f = 1;
                    break;
                }
            }
            if (f == 0)
                b[i].erase(b[i].begin() + i);
        }
        vector<int> max(k, 0);
        vector<int> tmp(k, 0);
        int at, bt;
        for (int i = k - nb; i <= na; i++) {
            int j = k - i;
            at = 0;
            bt = 0;
            f = 0;
            while (at + bt < k) {
                if (at >= i) {
                    tmp[at + bt] = b[j][bt];
                    bt++;
                } else {
                    if (bt >= j) {
                        tmp[at + bt] = a[i][at];
                        at++;
                    } else {
                        if (a[i][at] == b[j][bt]) {
                            int aat = at, bbt = bt;
                            while (aat < i && bbt < j && a[i][aat] == b[j][bbt]) {
                                aat++;
                                bbt++;
                            }
                            if (aat >= i && bbt >= j) {
                                tmp[at + bt] = a[i][at];
                                at++;
                            } else {
                                if (aat >= i) {
                                    tmp[at + bt] = b[j][bt];
                                    bt++;
                                } else {
                                    if (bbt >= j) {
                                        tmp[at + bt] = a[i][at];
                                        at++;
                                    } else {
                                        if (a[i][aat] > b[j][bbt]) {
                                            tmp[at + bt] = a[i][at];
                                            at++;
                                        } else {
                                            tmp[at + bt] = b[j][bt];
                                            bt++;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (a[i][at] > b[j][bt]) {
                                tmp[at + bt] = a[i][at];
                                at++;
                            } else {
                                tmp[at + bt] = b[j][bt];
                                bt++;
                            }
                        }
                    }
                }
                if (f == 0 && tmp[at + bt - 1] > max[at + bt - 1]) {
                    f = 1;
                }
                if (f == 0 && tmp[at + bt - 1] < max[at + bt - 1]) {
                    break;
                }
                if (f == 1) {
                    max[at + bt - 1] = tmp[at + bt - 1];
                }
            }
        }
        return max;
    }
};
