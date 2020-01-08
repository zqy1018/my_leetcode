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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edge(numCourses);
        vector<int> deg(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); ++i){
            int u = prerequisites[i][1], v = prerequisites[i][0];
            edge[u].push_back(v), ++deg[v];
        }
        queue<int> que;
        for (int i = 0; i < numCourses; ++i)
            if (!deg[i]) que.push(i);
        vector<int> ans;
        while (!que.empty()){
            int tp = que.front(), sz = edge[tp].size();
            que.pop(), ans.push_back(tp);
            for (int i = 0; i < sz; ++i){
                int v = edge[tp][i];
                --deg[v];
                if (!deg[v]) que.push(v);
            }
        }
        if (ans.size() == numCourses) 
            return ans;
        return vector<int>();
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
