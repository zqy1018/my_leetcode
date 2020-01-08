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
    string alphabetBoardPath(string target) {
        string ans;
        int posx[26], posy[26];
        for (int i = 0; i < 26; ++i)
            posx[i] = i / 5, posy[i] = i % 5;
        int lst = 0;
        for (char c: target){
            int tx = posx[c - 'a'], ty = posy[c - 'a'];
            if (lst == 25){
                for (int i = 5; i > tx; --i)   
                    ans.push_back('U');
                for (int i = 0; i < ty; ++i)    
                    ans.push_back('R');
            }else {
                int px = posx[lst], py = posy[lst];
                if (py < ty){
                    for (int i = py; i < ty; ++i) ans.push_back('R');
                }else {
                    for (int i = ty; i < py; ++i) ans.push_back('L');
                }
                if (px < tx){
                    for (int i = px; i < tx; ++i) ans.push_back('D');
                }else {
                    for (int i = tx; i < px; ++i) ans.push_back('U');
                }
            }
            ans.push_back('!');
            lst = c - 'a';
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
