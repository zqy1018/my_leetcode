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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> arr;
    TreeNode* build(int l, int r){
        if(l > r) return NULL;
        int mid = (l + r) >> 1;
        TreeNode *root = new TreeNode(arr[mid]);
        root->left = build(l, mid - 1);
        root->right = build(mid + 1, r);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        while(head != NULL) 
            arr.push_back(head->val), n++, head = head->next;
        return build(0, n - 1);
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
