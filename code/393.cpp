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
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for (int i = 0; i < n; ){
            if ((data[i] & 128) == 0) ++i;
            else{
                int res = 0;
                if ((data[i] & 224) == 192){
                    if (i + 1 >= n) return false;
                    res = 1;
                }else if ((data[i] & 240) == 224){
                    if (i + 2 >= n) return false;
                    res = 2;
                }else if ((data[i] & 248) == 240){
                    if (i + 3 >= n) return false;
                    res = 3;
                }else return false;
                for (int j = 1; j <= res; ++j)
                    if ((data[i + j] & 192) != 128)
                        return false;
                i += res + 1;
            }
        }
        return true;
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
