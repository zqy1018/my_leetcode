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
    int cnt[26];
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) return false;
        memset(cnt, 0, sizeof(cnt));
        cnt[0] = k / 26;
        for (int i = 1; i < 26; ++i){
            if (k >= i) cnt[i] = 1 + (k - i) / 26;
            else cnt[i] = 0;
        }
        int l = s.length();
        for (int i = 0; i < l; ++i){
            int d = t[i] - s[i];
            if (d < 0) d += 26;
            if (!cnt[d]) return false;
            --cnt[d];
        }
        return true;
    }
};
Solution sol;

int main(){

    return 0;
}
