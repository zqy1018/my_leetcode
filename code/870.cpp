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

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> id(n, 0), ans(n, 0);
        for (int i = 1; i < n; ++i) id[i] = i;
        sort(id.begin(), id.end(), [&B](int x, int y){ return B[x] < B[y]; });
        sort(A.begin(), A.end());
        int cur = 0, lst = n - 1;
        for (int i = 0; i < n; ++i){
            while (cur < n && A[cur] <= B[id[i]])
                ans[id[lst]] = A[cur], --lst, ++cur;
            if (cur == n) break;
            ans[id[i]] = A[cur], ++cur;
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
