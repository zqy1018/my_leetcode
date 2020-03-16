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
    bool vis[50005];
    bool canReach(vector<int>& arr, int start) {
        queue<int> que;
        que.push(start);
        vis[start] = true;
        int n = arr.size();
        while (!que.empty()){
            int h = que.front();
            que.pop();
            if (!arr[h]) return true;
            int to1 = h - arr[h], to2 = h + arr[h];
            if (to1 >= 0 && to1 < n && !vis[to1])
                vis[to1] = true, que.push(to1);
            if (to2 >= 0 && to2 < n && !vis[to2])
                vis[to2] = true, que.push(to2)  ;
        }
        return false;
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
