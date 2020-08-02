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
    int a[205];
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i){
            int cnt = 0;
            for (int j = n - 1; j >= 0; --j){
                if (grid[i][j] > 0){
                    break;
                }else ++cnt;
            }
            cnt = n - cnt;
            a[i] = cnt;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i){
            if (a[i] <= i + 1){
                continue;
            }else {
                // choudiao
                int j = i + 1;
                while (j < n && a[j] > i + 1)
                    ++j;
                if (j == n) return -1;
                for (int t = j; t > i; --t)
                    swap(a[t], a[t - 1]), ++ans;
            }
        }
        return ans;
    }
};
Solution sol;

int main(){

    return 0;
}
