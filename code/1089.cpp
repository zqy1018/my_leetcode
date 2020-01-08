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
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), i = 0, j = 0;
        while (j < n){
            if (!arr[i]) ++j;
            ++i, ++j;
        }
        if (j == n + 1) arr.push_back(0);
        --i;
        while (i >= 0)  {
            if (!arr[i]) arr[--j] = 0;
            arr[--j] = arr[i], --i;
        }
        if (arr.size() > n) arr.pop_back();
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
