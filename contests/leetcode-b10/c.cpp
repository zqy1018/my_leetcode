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
    vector<int> ans;
    vector<long long> t1, t2;
    vector<int> countSteppingNumbers(int low, int high) {
        if (low == 0) ans.push_back(0);
        for (int i = 1; i <= 9; ++i)
            t1.push_back(i);
        for (int i = 1; i <= 10; ++i){
            for (long long v: t1){
                if (v >= low && v <= high) ans.push_back(v);
                int dd = v % 10;
                if (dd > 0) t2.push_back(v * 10 + dd - 1);
                if (dd < 9) t2.push_back(v * 10 + dd + 1);
            }
            t1.clear();
            while (!t2.empty())
                t1.push_back(t2.back()), t2.pop_back();
        }
        sort(ans.begin(), ans.end());
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
