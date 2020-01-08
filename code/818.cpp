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

int f[40005][20], g[40005][20];
int lim, logg;
class Solution {
public:
    int racecar(int target) {
        memset(f, 0x3f, sizeof(f));
        memset(g, 0x3f, sizeof(g));
        for (logg = 0; (1 << logg) < target + 2; ++logg) ;
        lim = (1 << logg) - 1;
        f[0 + lim][0] = 0;
        int ans = 0x3f3f3f3f;
        queue<int> qcur, qst;
        qcur.push(0), qst.push(0);
        while (!qcur.empty()){
            int cur = qcur.front(), st = qst.front();
            qcur.pop(), qst.pop();
            if (st == -1){
                if (cur - 1 >= -lim && g[cur - 1 + lim][1] == 0x3f3f3f3f) 
                    g[cur - 1 + lim][1] = g[cur + lim][0] + 1, 
                    qcur.push(cur - 1), qst.push(-2);
                if (f[cur + lim][0] == 0x3f3f3f3f) 
                    f[cur + lim][0] = g[cur + lim][0] + 1,
                    qcur.push(cur), qst.push(0);
            }else if (st < 0){
                st = -1 - st;
                int t = (1 << st);
                if (cur - t >= -lim && g[cur - t + lim][st + 1] == 0x3f3f3f3f)
                    g[cur - t + lim][st + 1] = g[cur + lim][st] + 1,
                    qcur.push(cur - t), qst.push(-st - 2);
                if (f[cur + lim][0] == 0x3f3f3f3f) 
                    f[cur + lim][0] = g[cur + lim][st] + 1,
                    qcur.push(cur), qst.push(0);
            }else if (st == 0){
                if (cur + 1 <= lim && f[cur + 1 + lim][1] == 0x3f3f3f3f) 
                    f[cur + 1 + lim][1] = f[cur + lim][0] + 1, 
                    qcur.push(cur + 1), qst.push(1);
                if (g[cur + lim][0] == 0x3f3f3f3f) 
                    g[cur + lim][0] = f[cur + lim][0] + 1,
                    qcur.push(cur), qst.push(-1);
            }else {
                int t = (1 << st);
                if (cur + t <= lim && f[cur + t + lim][st + 1] == 0x3f3f3f3f)
                    f[cur + t + lim][st + 1] = f[cur + lim][st] + 1,
                    qcur.push(cur + t), qst.push(st + 1);
                if (g[cur + lim][0] == 0x3f3f3f3f) 
                    g[cur + lim][0] = f[cur + lim][st] + 1,
                    qcur.push(cur), qst.push(-1);
            }
        }
        for (int i = 0; i <= logg; ++i)
            ans = min(ans, f[target + lim][i]), 
            ans = min(ans, g[target + lim][i]);
        return ans;
    }
};
Solution sol;
void init(){
    int n = read();
    cout << sol.racecar(n) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
