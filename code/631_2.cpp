

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

int vec[30][30][15][4];
int val[30][30], siz[30][30];
int n, m;
bool vis[30][30];
void update(int x, int y){
    int res = 0;
    for (int T = 0; T < siz[x][y]; ++T){
        int r1 = vec[x][y][T][0];
        int r2 = vec[x][y][T][1];
        int c1 = vec[x][y][T][2];
        int c2 = vec[x][y][T][3];
        for (int i = r1; i <= r2; ++i)  
            for (int j = c1; j <= c2; ++j){
                if (siz[i][j] && !vis[i][j])
                    vis[i][j] = true, update(i, j);
                res += val[i][j]; 
            }
    }
    val[x][y] = res;
}
void upd(){
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) 
            if (siz[i][j] && !vis[i][j])
                vis[i][j] = true, update(i, j);
}
class Excel {
public:
    Excel(int H, char W) {
        n = H, m = W - 'A' + 1;
        memset(val, 0, sizeof(val));
        memset(siz, 0, sizeof(siz));
    }
    
    void set(int r, char c, int v) {
        int cc = c - 'A' + 1;
        siz[r][cc] = 0; 
        val[r][cc] = v;
        upd();
    }
    
    int get(int r, char c) {
        upd();
        return val[r][c - 'A' + 1];
    }
    
    int sum(int r, char c, vector<string> strs) {
        int cc = c - 'A' + 1;
        siz[r][cc] = 0;
        int nn = strs.size(); 
        for (int T = 0; T < nn; ++T){
            string& s = strs[T];
            int ll = s.length();
            if (ll <= 3){
                // 单点
                int r1 = s[1] - '0';
                if (ll == 3) r1 = r1 * 10 + s[2] - '0';
                vec[r][cc][siz[r][cc]][0] = vec[r][cc][siz[r][cc]][1] = r1; 
                vec[r][cc][siz[r][cc]][2] = vec[r][cc][siz[r][cc]][3] = s[0] - 'A' + 1; 
            }else {
                // 区间
                int r1 = 0, r2 = 0;
                int c1 = s[0] - 'A' + 1, c2;
                int cur = 1;
                while (s[cur] != ':')
                    r1 = r1 * 10 + s[cur] - '0', ++cur;
                c2 = s[++cur] - 'A' + 1;
                ++cur;
                r2 = s[cur++] - '0';
                if (cur < ll) r2 = r2 * 10 + s[cur] - '0';
                vec[r][cc][siz[r][cc]][0] = r1, 
                vec[r][cc][siz[r][cc]][1] = r2,
                vec[r][cc][siz[r][cc]][2] = c1,
                vec[r][cc][siz[r][cc]][3] = c2;
            }
            siz[r][cc]++;
        }
        upd();
        return val[r][cc];
    }
};
void init(){
    Excel e(3, 'C');
    e.sum(1, 'A', vector<string>{"A2"});
    e.set(2, 'A', 1);
    cout << e.get(1, 'A') << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
