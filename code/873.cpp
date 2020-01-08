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
    int lenLongestFibSubseq(vector<int>& A) {
        int ans = 0, n = A.size(), maxi = 0;
        unordered_set<int> mp;
        for (int i = 0; i < n; ++i) 
            mp.insert(A[i]), maxi = max(maxi, A[i]);
        for (int i = 0; i < n - 2; ++i){
            for (int j = i + 1; j < n - 1; ++j){
                int lst1 = A[i], lst2 = A[j], cnt = 2;
                while (lst1 + lst2 <= maxi && mp.count(lst1 + lst2)){
                    int tmp = lst1 + lst2;
                    lst1 = lst2, lst2 = tmp;
                    ++cnt;
                }
                if (cnt >= 3) ans = max(ans, cnt); 
            }
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
