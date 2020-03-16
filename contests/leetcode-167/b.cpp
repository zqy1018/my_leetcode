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
    vector<int> sequentialDigits(int low, int high) {
        vector<int> vec;
        for (int l = 2; l <= 9; ++l){
            for (int i = 1; i + l <= 10; ++i){
                int x = 0;
                for (int j = i; j <= i + l - 1; ++j)
                    x = x * 10 + j;
                if (x <= high && x >= low)  
                    vec.push_back(x);
            }
        }
        sort(vec.begin(), vec.end());
        return vec;
    }
};
Solution sol;
void init(){
    vector<int> ans = sol.sequentialDigits(1000, 13000);
    for (int i: ans) cout << i << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
