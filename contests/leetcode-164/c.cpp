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

bool ok[10005];
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string> > ans;
        int ll = searchWord.length();
        string em("");
        memset(ok, 0, sizeof(ok));
        int n = products.size();
        for (int i = 1; i <= ll; ++i){
            em.push_back(searchWord[i - 1]);
            vector<string> curans;
            for (int j = 0; j < n && curans.size() < 3; ++j){
                if (ok[j]) continue;
                if (products[j].substr(0, i) != em) 
                    ok[j] = true;
                else {
                    curans.push_back(products[j]);
                }
            }
            ans.push_back(curans);
        }
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
