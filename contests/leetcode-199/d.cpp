#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

template<typename T1, typename T2>
ostream& operator << (ostream& os, const pair<T1, T2>& p){
    os << p.first << " " << p.second << endl;
    return os;
}

inline int lowbit(int x){
    return x & (-x);
}
inline int sgn(int x){
    return (x < 0 ? -1: (x > 0 ? 1: 0));
}

const int M = 1000000007;
inline int modadd(int x, int y){
    return (x + y >= M ? x + y - M: x + y);
}
int poww(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1)
            res = 1ll * res * a % M;
        a = 1ll * a * a % M, b >>= 1;
    }
    return res;
}

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

class Solution {
    int l[105][2], tot;
    int f[105][105], sum[105];
    inline int get(int x){
        if (x == 0) return -1;
        if (x == 1) return 0;
        if (x <= 9) return 1;
        if (x <= 99) return 2;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        tot = 0;
        int n = s.length();
        sum[0] = 0;
        for (int i = 0; i < n; ){
            int j = i;
            while (j < n && s[i] == s[j])
                ++j;
            l[++tot][0] = s[i], l[tot][1] = j - i;
            sum[tot] = sum[tot - 1] + j - i;
            i = j;
        }
        memset(f, 0x3f,sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= tot; ++i){
            for (int j = 0; j <= k; ++j){
                if (j >= sum[i]){
                    f[i][j] = 0;
                    continue;
                }
                for (int t = 0; t <= l[i][1]; ++t){
                    if (j < t) break;
                    f[i][j] = min(f[i][j], f[i - 1][j - t] + 1 + get(l[i][1] - t));
                }
                int th = l[i][1], tr = 0;
                for (int t = i - 1; t >= 1; --t){
                    if (j >= sum[i] - sum[t])
                        f[i][j] = min(f[i][j], f[t][j - sum[i] + sum[t]]);
                    if (l[t][0] == l[i][0]){
                        th += l[t][1];
                        for (int u = tr; u < th + tr; ++u){
                            if (j < u) break;
                            f[i][j] = min(f[i][j], f[t - 1][j - u] + 1 + get(th - (u - tr)));
                        }
                    }else tr += l[t][1];

                    if (j < tr) break;
                }
            }
        }
        return f[tot][k];
    }
};
Solution sol;

int main(){

    return 0;
}
