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


class Excel {    
    struct Rec{
        int r1, r2, c1, c2;
        Rec(int _r1, int _r2, int _c1, int _c2): 
            r1(_r1), r2(_r2), c1(_c1), c2(_c2){}
        Rec(int _r, int _c): r1(_r), r2(_r), c1(_c), c2(_c){}
    }; 
    vector<Rec> vec[30][30];
    int val[30][30];
    int n, m;
    bool vis[30][30];
    void update(int x, int y){
        int res = 0;
        for (auto& r: vec[x][y])
            for (int i = r.r1; i <= r.r2; ++i)  
                for (int j = r.c1; j <= r.c2; ++j){
                    if (!vec[i][j].empty() && !vis[i][j])
                        vis[i][j] = true, update(i, j);
                    res += val[i][j]; 
                }
        val[x][y] = res;
    }
    void upd(){
        memset(vis, 0, sizeof(vis));
        cout << vec[1][1].empty() << endl;
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= m; ++j) 
                if (!vec[i][j].empty() && !vis[i][j])
                    vis[i][j] = true, update(i, j);
    }
public:
    Excel(int H, char W) {
        n = H, m = W - 'A' + 1;
        memset(val, 0, sizeof(val));
    }
    
    void set(int r, char c, int v) {
        int cc = c - 'A' + 1;
        if (!vec[r][cc].empty())
            vec[r][cc].clear();
        val[r][cc] = v;
        upd();
    }
    
    int get(int r, char c) {
        upd();
        cout << val[2][1] << endl;
        return val[r][c - 'A' + 1];
    }
    
    int sum(int r, char c, vector<string> strs) {
        int cc = c - 'A' + 1;
        if (!vec[r][cc].empty())
            vec[r][cc].clear();
        for (auto& s: strs){
            if (s.length() <= 3){
                // 单点
                int r1 = s[1] - '0';
                if (s.length() == 3) r1 = r1 * 10 + s[2] - '0';
                vec[r][cc].push_back(Rec(r1, s[0] - 'A' + 1));
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
                if (cur < s.length()) r2 = r2 * 10 + s[cur] - '0';
                vec[r][cc].push_back(Rec(r1, r2, c1, c2));
            }

            cout << vec[r][cc].size() << endl << endl;
        }
        cout << vec[r][cc].size() << endl << endl;
        upd();
        return val[r][cc];
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(H, W);
 * obj->set(r,c,v);
 * int param_2 = obj->get(r,c);
 * int param_3 = obj->sum(r,c,strs);
 */
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
