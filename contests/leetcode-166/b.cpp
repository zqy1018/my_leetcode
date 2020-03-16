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

int lst[5005], to[5005];
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        memset(lst, -1, sizeof(lst));
        memset(to, -1, sizeof(to));
        int n = groupSizes.size();
        for (int i = 0; i < n; ++i){
            int tt = groupSizes[i];
            if (lst[tt] == -1){
                int cur = ans.size();
                ans.push_back(vector<int>());
                if (tt == 1)
                    ans[cur].push_back(i), to[i] = cur;
                else 
                    ans[cur].push_back(i), lst[tt] = i, to[i] = cur;
            }else {
                int iid = to[lst[tt]];
                ans[iid].push_back(i);
                to[i] = iid;
                if (ans[iid].size() == tt)
                    lst[tt] = -1;
                else 
                    lst[tt] = i;
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
