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
    int f[50005], sum[50005];
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        sum[n] = sum[n + 1] = sum[n + 2] = 0;
        for (int i = n - 1; i >= 0; --i)
            sum[i] = sum[i + 1] + stoneValue[i];
        stoneValue.push_back(0);
        stoneValue.push_back(0);
        f[n] = f[n + 1] = f[n + 2] = 0;
        for (int i = n - 1; i >= 0; --i){
            f[i] = INT_MIN;
            f[i] = max(f[i], stoneValue[i] + sum[i + 1] - f[i + 1]);
            f[i] = max(f[i], stoneValue[i] + stoneValue[i + 1] + sum[i + 2] - f[i + 2]);
            f[i] = max(f[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] + sum[i + 3] - f[i + 3]);
        }
        int xs = f[0], hs = sum[0] - f[0];
        if (xs > hs) return "Alice" ;
        else if (xs < hs) return "Bob";
        return "Tie"    ;
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
