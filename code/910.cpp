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
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size(), ans = A.back() - A.front();
        for (int i = 0; i < n - 1; ++i){
            int t = INT_MIN;
            t = max(t, A[i] - A[0]);
            t = max(t, abs(A[i + 1] - A[0] - K - K));
            t = max(t, abs(A[n - 1] - A[0] - K - K));
            t = max(t, abs(A[i + 1] - A[i] - K - K));
            t = max(t, abs(A[n - 1] - A[i] - K - K));
            t = max(t, A[n - 1] - A[i + 1]);
            ans = min(ans, t);
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
