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
    int f[32800];
    queue<int> q, cnt;
public:
    int countArrangement(int N) {
        f[0] = 1;
        q.push(0), cnt.push(0);
        while (!q.empty()){
            int h = q.front(), ccnt = cnt.front();
            q.pop(), cnt.pop();
            for (int i = 0, t = 1; i < N; ++i, t <<= 1){
                if (t & h) continue;
                if ((i + 1) % (ccnt + 1) != 0 && (ccnt + 1) % (i + 1) != 0)
                    continue;
                if (!f[t | h]) q.push(t | h), cnt.push(ccnt + 1);
                f[t | h] += f[h];
            }
        }
        return f[(1 << N) - 1];
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
