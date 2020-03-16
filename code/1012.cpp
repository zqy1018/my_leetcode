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
    int nn, ws, ans, fac[11];
    int get(int x){
        int res = 0;
        while (x > 0) x /= 10, ++res;
        return res;
    }
    void dfs(int cur, int acc, int vis){
        if (cur == ws){
            if (acc <= nn) --ans;
            return ;
        }
        for (int i = 0; i < 10; ++i)
            if (!(vis & (1 << i)))
                dfs(cur + 1, acc * 10 + i, vis | (1 << i));
    }
public:
    int numDupDigitsAtMostN(int N) {
        if (N <= 10) return 0; 
        ans = N;
        if (N == 1000000000) --N, --ans;
        ws = get(N), nn = N;
        ans -= 9;
        fac[1] = 1;
        for (int i = 2; i <= 10; ++i)
            fac[i] = fac[i - 1] * i;
        for (int i = 2; i < ws; ++i)
            ans -= fac[10] / fac[10 - i] - fac[9] / fac[10 - i];
        for (int i = 1; i <= 9; ++i)
            dfs(1, i, (1 << i));
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
