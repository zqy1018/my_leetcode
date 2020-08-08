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

int pos[10005];
class Solution {
public:
    int longestAwesome(string s) {
        memset(pos, -1, sizeof(pos));
        int res = 0, l = s.length();
        pos[0] = 0;
        int ans = 1;
        for (int i = 1; i <= l; ++i){
            res ^= (1 << (s[i - 1] - '0'));
            if (pos[res] >= 0) ans = max(ans, i - pos[res]);
            for (int j = 0; j < 10; ++j){
                if (pos[res ^ (1 << j)])
                    ans = max(ans, i - pos[res ^ (1 << j)]);
            }
            if (pos[res] < 0) pos[res] = i;
        }
        return ans;
    }
};
Solution sol;

int main(){

    return 0;
}
