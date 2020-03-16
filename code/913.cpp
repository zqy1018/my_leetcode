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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

class Solution {
    int win[205][205][2];
    bool vis[205][205][2];
    int dfs(int p1, int p2, int turn, vector<vector<int>>& graph){
        if (win[p1][p2][turn] >= 0) return win[p1][p2][turn];
        if (p1 == p2)
            return (win[p1][p2][turn] = 2);
        if (p1 == 0)
            return (win[p1][p2][turn] = 1);
        if (vis[p1][p2][turn])
            return 0;
        vis[p1][p2][turn] = true;
        if (turn){
            bool flag = true;
            for (int t2: graph[p2]){
                if (t2 == 0) continue;
                int res = dfs(p1, t2, 0, graph);
                if (res == 2) {
                    win[p1][p2][turn] = 2;
                    break;
                }else if (res == 0) flag = false;
            }
            if (win[p1][p2][turn] != 2){
                if (flag) win[p1][p2][turn] = 1;
                else win[p1][p2][turn] = 0;
            }
        }else {
            bool flag = true;
            for (int t1: graph[p1]){
                int res = dfs(t1, p2, 1, graph);
                if (res == 1) {
                    win[p1][p2][turn] = 1;
                    break;
                }else if (res == 0) flag = false;
            }
            if (win[p1][p2][turn] != 1){
                if (flag) win[p1][p2][turn] = 2;
                else win[p1][p2][turn] = 0;
            }
        }
        return win[p1][p2][turn];
    }
public:
    int catMouseGame(vector<vector<int>>& graph) {
        memset(win, -1, sizeof(win));
        return dfs(1, 2, 0, graph);
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
