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
    
public:
    vector<int> closestDivisors(int num) {
        int a = -1, b = -1;
        int ans = INT_MAX;
        ++num;
        for (int i = 1; i * i <= num; ++i){
            if (num % i != 0) continue;
            int tt = abs(num / i - i);
            if (tt < ans) ans = tt, a = i, b = num / i;
        }
        ++num;
        for (int i = 1; i * i <= num; ++i){
            if (num % i != 0) continue;
            int tt = abs(num / i - i);
            if (tt < ans) ans = tt, a = i, b = num / i;
        }
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        return res;
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
