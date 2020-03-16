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


int fa[100005], cnt[100005];
class Solution {
public:
    vector<int> G[100005];
    int Find(int x){
        return (x == fa[x] ? x: (fa[x] = Find(fa[x])));
    }
    void Union(int x, int y){
        int fx = Find(x), fy = Find(y);
        if (fx == fy) return ;
        if (fx < fy) fa[fy] = fx;
        else fa[fx] = fy;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        for (int i = 0; i < n; ++i)
            fa[i] = i, cnt[i] = 0;
        for (vector<int>& e: pairs){
            Union(e[0], e[1]);
        }
        for (int i = 0; i < n; ++i) Find(i);
        for (int i = 0; i < n; ++i){
            G[fa[i]].push_back(s[i]);
        }
        for (int i = 0; i < n; ++i)
            if (!G[i].empty()) sort(G[i].begin(), G[i].end());
        for (int i = 0; i < n; ++i)
            s[i] = G[fa[i]][cnt[fa[i]]], cnt[fa[i]]++;
        return s;
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
