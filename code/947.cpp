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
    int Find(int x){
        return (x == fa[x] ? x: (fa[x] = Find(fa[x])));
    }
    void Union(int x, int y){
        int fx = Find(x), fy = Find(y);
        if (fx == fy) return ;
        if (siz[fx] > siz[fy]){
            fa[fy] = fx, siz[fx] += siz[fy];
        }else {
            fa[fx] = fy, siz[fy] += siz[fx];
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        fa = vector<int>(n, 0);
        siz = vector<int>(n, 1);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) fa[i] = i;
        for (int i = 0; i < n; ++i){
            int x = stones[i][0];
            if (mp.count(x))
                Union(i, mp[x]);
            mp[x] = i;
        }
        mp.clear();
        for (int i = 0; i < n; ++i){
            int y = stones[i][1];
            if (mp.count(y))
                Union(i, mp[y]);
            mp[y] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) 
            if (fa[i] == i) ans += siz[i] - 1;
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
