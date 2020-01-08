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
    vector<int> dfn, low;
    stack<int> st;
    vector<char> in;
    int D;
    void scc(int cur, vector<vector<int>>& graph){
        dfn[cur] = low[cur] = ++D;
        in[cur] = 1;
        st.push(cur);
        for (int v: graph[cur]){
            if (!dfn[v]) scc(v, graph), low[cur] = min(low[cur], low[v]);
            else if (in[v] == 1) {
                low[cur] = min(low[cur], dfn[v]);
            }
        }
        if (dfn[cur] == low[cur]){
            if (st.top() == cur){
                st.pop(), in[cur] = 0;
            }else{
                do{
                    in[st.top()] = -1;
                    st.pop();
                }while (st.top() != cur);
                st.pop(), in[cur] = -1;
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        dfn = vector<int>(n, 0);
        low = vector<int>(n, 0);
        in = vector<char>(n, 0);
        D = 0;
        for (int i = 0; i < n; ++i) 
            if (!dfn[i]) scc(i, graph);
        vector<int> ans;
        for (int i = 0; i < n; ++i) 
            if (in[i] == 0) 
                ans.push_back(i);
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
