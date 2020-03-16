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
    int du[10005]; 
    int ccnt;
    void dfs(int cur, vector<int>& leftChild, vector<int>& rightChild){
        if (cur == -1) return ;
        ++ccnt;
        dfs(leftChild[cur], leftChild, rightChild);
        dfs(rightChild[cur], leftChild, rightChild);
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int cnt = 0;
        for (int i = 0; i < n; ++i){
            if (leftChild[i] != -1) ++du[leftChild[i]], ++cnt;
            if (rightChild[i] != -1) ++du[rightChild[i]], ++cnt;
        }
        if (cnt != n - 1) return false;
        int rt = -1;
        for (int i = 0; i < n; ++i){
            if (!du[i]){
                if (rt != -1) return false;
                rt = i;
            }
        }
        if (rt < 0) return false;
        ccnt = 0;
        dfs(rt, leftChild, rightChild);
        return ccnt == n;
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
