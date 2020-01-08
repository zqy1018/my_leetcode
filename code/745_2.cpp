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

int lis[15005];
class WordFilter {
public:
    vector<string> vec;
    WordFilter(vector<string>& words) {
        vec = words;
        int n = words.size();
        for (int i = 0; i < n; ++i) 
            lis[i] = i;
        sort(lis, lis + n, [&words](){

        });
    }
    
    int f(string prefix, string suffix) {
        int st = lower_bound(vec.begin(), vec.end(), prefix) - vec.begin();
        int ed = upper_bound(vec.begin(), vec.end(), prefix) - vec.begin();
        for (int i = st; i < ed; ++i)
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
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
