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
    int du[5005], dis[5005];
    vector<int> to[5005];
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        for (auto& p: relations)
            ++du[p[1]], to[p[0]].push_back(p[1]);
        queue<int> q;
        int cnt = 0, ans = 1;
        for (int i = 1; i <= N; ++i)    
            if (!du[i])
                dis[i] = 1, q.push(i);
        while (!q.empty()){
            int h = q.front();
            q.pop(), ++cnt;
            for (int v: to[h]){
                --du[v], dis[v] = max(dis[v], dis[h] + 1);
                if (!du[v]) q.push(v), ans = max(ans, dis[v]);
            }
        }
        if (cnt < N) return -1;
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
