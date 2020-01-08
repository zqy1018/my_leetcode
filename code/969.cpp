

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
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        for (int i = A.size() - 1; i > 0; --i)  {
            if (A[i] == i + 1) 
                continue;
            int j = i;
            for (--j; A[j] != i + 1; --j)
                ;
            if (j)
                reverse(A.begin(), A.begin() + j + 1), ans.push_back(j + 1);
            reverse(A.begin(), A.begin() + i + 1), ans.push_back(i + 1);
        }
        return ans;
    }
};
Solution sol;
int main(){
    init();
    solve();
    return 0;
}
