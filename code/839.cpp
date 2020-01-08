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

class Solution {
public:
    vector<int> fa, siz;
    vector<unsigned long long> h, hh;
    int Find(int x){
        return (fa[x] == x ? x: (fa[x] = Find(fa[x])));
    }
    void Union(int x, int y){
        int fx = Find(x), fy = Find(y);
        if (fx == fy) return ;
        if (siz[fx] > siz[fy]) siz[fx] += siz[fy], fa[fy] = fx;
        else siz[fy] += siz[fx], fa[fx] = fy;
    }
    int numSimilarGroups(vector<string>& A) {
        unordered_map<unsigned long long, int> mp;
        int n = A.size(), l = A[0].length(), ans = 0;
        fa = vector<int>(n, 0);
        siz = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) 
            fa[i] = i, siz[i] = 1;
        h.push_back(1);
        for (int i = 1; i <= l; ++i)
            h.push_back(h.back() * 9982443ull);
        for (int i = 0; i < n; ++i) {
            unsigned long long h1 = 0;
            for (int j = 0; j < l; ++j)
                h1 = h1 * 9982443ull + A[i][j];
            if (mp.count(h1)) Union(i, mp[h1]);
            else mp[h1] = i; 
            hh.push_back(h1);
        }    
        for (int i = 0; i < n; ++i) {
            bool flag = true;
            for (int j = 0; j < l; ++j)
                for (int k = 0; k < j; ++k) 
                    if (A[i][j] != A[i][k]){
                        unsigned long long h1 = hh[i];
                        h1 -= A[i][j] * h[l - j - 1], h1 -= A[i][k] * h[l - k - 1];
                        h1 += A[i][k] * h[l - j - 1], h1 += A[i][j] * h[l - k - 1];
                        if (mp.count(h1))
                            Union(i, mp[h1]), flag = false;
                    }
        }
        for (int i = 0; i < n; ++i) {
            Find(i);
            if (fa[i] == i) ++ans;            
        }
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
