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
    bool vis[1000005];
    queue<int> q;
    int step[1000005];
public:
    int minJump(vector<int>& jump) {
        memset(step, 0x3f, sizeof(step));
        int cur = 0;
        vis[0] = true, q.push(0);
        step[0] = 0;
        int n = jump.size();
        while (!q.empty()){
            int h = q.front();
            while (cur < h && cur < n){
                while (cur < n && vis[cur]){
                    ++cur;
                }
                if (cur >= h || cur == n) break;
                step[cur] = step[h] + 1;
                vis[cur] = true;
                q.push(cur);
            }
            if (h + jump[h] < n){
                if (!vis[h + jump[h]]){
                vis[h + jump[h]] = true;
                step[h + jump[h]] = step[h] + 1;
                q.push(h + jump[h]);}
            }else return step[h];
        }
        return 0;
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
