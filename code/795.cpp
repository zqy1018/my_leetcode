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
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        A.push_back(1000000001);
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < A.size(); ++i){
            while (!st.empty() && A[i] >= A[st.top()]){
                int l1 = st.top();
                st.pop();
                int l2 = (st.empty() ? -1: st.top());
                if (A[l1] <= R && A[l1] >= L)
                    ans += (i - l1) * (l1 - l2);
            }
            st.push(i);
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
