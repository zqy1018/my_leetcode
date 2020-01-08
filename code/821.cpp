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
    vector<int> shortestToChar(string S, char C) {
        int lst, cur, n = S.size();
        for (lst = 0; S[lst] != C; ++lst)
            ;
        vector<int> ans(S.size(), 0);
        for (int i = lst - 1; i >= 0; --i)
            ans[i] = lst - i;
        for (; ; ){
            for (cur = lst + 1; cur < n && S[cur] != C; ++cur)
                ;
            if (cur == n) break;
            for (int i = lst + 1, j = cur - 1; i <= j; ++i, --j)
                ans[i] = ans[j] = i - lst; 
            lst = cur;
        }
        for (int i = lst + 1; i < n; ++i)
            ans[i] = i - lst;
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
