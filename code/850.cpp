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


int seg[1005], mini[1005], yy[205], id[205], sum[205];
int siz, _a, _b, val;
pair<int, int> pp[205];
void maintain(int id, int l, int r){
    if (mini[id] > 0) seg[id] = sum[r] - sum[l - 1];
    else seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
void update(int id, int l, int r){
    if (l > _b || r < _a) return ;
    if (l >= _a && r <= _b){
        mini[id] += val;
        maintain(id, l, r);
        return ;
    }
    update(id << 1, l, (l + r) >> 1);
    update(id << 1 | 1, (l + r + 1) >> 1, r);
    maintain(id, l, r);
}
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        for (int i = 0; i < n; ++i){
            pp[i << 1].first = rectangles[i][0], 
            pp[i << 1].second = i + 1,
            pp[i << 1 | 1].first = rectangles[i][2], 
            pp[i << 1 | 1].second = -i - 1;
            yy[i << 1] = rectangles[i][1], yy[i << 1 | 1] = rectangles[i][3];
        }
        sort(pp, pp + n + n);
        sort(yy, yy + n + n);
        for (int i = 0; i < n; ++i){
            id[i << 1] = lower_bound(yy, yy + n + n, rectangles[i][1]) - yy, 
            id[i << 1 | 1] = lower_bound(yy, yy + n + n, rectangles[i][3]) - yy;
        }
        sum[0] = 0;
        for (int i = 1; i < n + n; ++i)
            sum[i] = sum[i - 1] + yy[i] - yy[i - 1];
        for (siz = 1; siz < n + n - 1; siz <<= 1)
            ;

        memset(seg, 0, sizeof(seg));
        memset(mini, 0, sizeof(mini));
        long long ans = 0;
        int lst = pp[0].first;
        for (int i = 0; i < n + n; ++i){
            int xx = pp[i].first, pos = pp[i].second;
            int rid = (pos < 0 ? -pos: pos) - 1;
            _a = id[rid << 1] + 1, _b = id[rid << 1 | 1];
            ans += 1ll * seg[1] * (xx - lst);
            if (pos > 0){
                val = 1, update(1, 1, siz);
            }else {
                val = -1, update(1, 1, siz);
            }
            lst = xx;
        } 
        return ans % 1000000007;
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
