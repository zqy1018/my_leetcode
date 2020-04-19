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
    int fib[1005];
public:
    int findMinFibonacciNumbers(int k) {
        fib[1] = fib[2] = 1;
        for (int i = 3; i <= 46; ++i)
            fib[i] = fib[i - 1] + fib[i - 2];
        int ans = 0;
        for (int i = 46; i >= 1; --i){
            if (k % fib[i] == 0){
                ans += k / fib[i];
                break;
            }else {
                ans += k / fib[i]   ;
                k %= fib[i];
            }
        }
        return ans;
        
    }
};
Solution sol;
void init(){
    sol.findMinFibonacciNumbers(10);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
