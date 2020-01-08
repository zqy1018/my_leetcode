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

int f[4100][12], bef[4100][12], dis[12][12];
class Solution {
public:
    inline int lowbit(int x){ return x & (-x); }
    unordered_map<int, int> mp;
    void init(int n){
        for (int i = 0; i < n; ++i)
            mp[1 << i] = i;
    }
    void dfs(int di, int dj){
        if (f[di][dj] < 0x3f3f3f3f) return ;
        int dii = di - (1 << dj);
        for (int i = dii, j = lowbit(i); i > 0; i -= j, j = lowbit(i)){
            int id = mp[j];
            dfs(dii, id);
            // do something...
        }
    }
    string shortestSuperstring(vector<string>& A) {
        memset(f, 0x3f, sizeof(f));
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            int li = A[i].length();
            for (int j = 0; j < n; ++j){
                if (i == j) continue;
                int maxlen = min(A[i].length(), A[j].length()), k = maxlen;
                for (; k >= 1; --k){
                    bool flag = true;
                    for (int u = 0; u < k; ++u){
                        if (A[i][li - k + u] != A[j][u]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) break;
                }
                dis[i][j] = A[j].length() - k;
            }
        }
        for (int i = 0; i < n; ++i)
            mp[1 << i] = i;
        for (int i = 0; i < n; ++i) 
            f[1 << i][i] = A[i].length(), bef[1 << i][i] = 0;
        for (int i = 0; i < n; ++i)
            dfs((1 << n) - 1, i);
        int ans[12], minp = 0;
        for (int i = 1; i < n; ++i) 
            if (f[(1 << n) - 1][i] < f[(1 << n) - 1][minp])
                minp = i;
        cout << f[(1 << n) - 1][minp] << endl;
        for (int i = minp, j = (1 << n) - 1, k = n - 1; j > 0; --k)
            ans[k] = i, i = bef[j][i], j -= (1 << ans[k]);
        string anss = A[ans[0]];
        for (int i = 1; i < n; ++i)
            anss += A[ans[i]].substr(A[ans[i]].length() - dis[ans[i - 1]][ans[i]]);
        return anss;
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
