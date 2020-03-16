#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* root) {
    return root->left == NULL && root->right == NULL;
}

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
class Solution {
    int f[10][260];
    int cnt[260];
public:
    int maxStudents(vector<vector<char>>& seats) {
        int n = seats.size(), m = seats[0].size();
        int bin = (1 << m);
        memset(f, -1, sizeof(f));
        for (int i = 1; i < bin; ++i){
            cnt[i] = cnt[i >> 1] + (i & 1);
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i){
            int dd = 0;
            for (int j = 0, t = 1; j < m; ++j, t <<= 1)
                if (seats[i - 1][j] == '#') 
                    dd = (dd | t); 
            for (int j = 0; j < bin; ++j){
                if (dd & j) continue;
                if ((j & (j << 1)) || (j & (j >> 1))) continue;
                for (int k = 0; k < bin; ++k){
                    if (f[i - 1][k] >= 0){
                        int tt1 = ((j >> 1) & k);
                        int tt2 = ((j << 1) & k);
                        if (!tt1 && !tt2)
                            f[i][j] = max(f[i][j], f[i - 1][k] + cnt[j]);
                    }
                }
            }   
        }

        int ans = 0;
        for (int i = 0; i < bin; ++i)
            ans = max(ans, f[n][i]);
        return ans;
    }
};
Solution sol;
void init(){
    
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
