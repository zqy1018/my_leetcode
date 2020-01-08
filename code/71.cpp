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

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ans;
        for (int i = 0; i < path.length(); ){
            int j = i;
            if (path[i] == '/'){
                while (j < path.length() && path[j] == '/')
                    ++j;
            }else{
                bool isallpoint = true;
                while (j < path.length() && path[j] != '/'){
                    if (path[j] != '.') isallpoint = false;
                    ++j;
                }
                if (isallpoint){
                    if (j - i == 2 && !ans.empty()) ans.pop(); 
                    else if (j - i > 2) ans.push(path.substr(i, j - i));
                }else
                    ans.push(path.substr(i, j - i));
            }
            i = j;
        }
        if (ans.empty()) return string("/");
        string res("");
        while (!ans.empty()){
            res = string("/") + ans.top() + res;
            ans.pop();
        }
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
