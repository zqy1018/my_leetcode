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
    vector<int> vis;
    vector<vector<int>> edge;
    bool ans;
    void dfs(int cur){
        for (int v: edge[cur]){
            if (vis[v] == 1) {
                ans = false;
                return ;
            }else if (vis[v] == 0){
                vis[v] = 1, dfs(v);
            }
            if (!ans) break;
        }
        vis[cur] = -1;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vis = vector<int>(numCourses, 0);
        edge = vector<vector<int>>(numCourses, vector<int>());
        ans = true;
        for (int i = 0; i < prerequisites.size(); ++i)
            edge[prerequisites[i][0]].push_back(prerequisites[i][1]);
        for (int i = 0; i < numCourses && ans; ++i){
            if (vis[i] == 0)
                vis[i] = 1, dfs(i);
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
