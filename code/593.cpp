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
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (p1[0] == p2[0] && p2[0] == p3[0] && p3[0] == p4[0]) return false;
        if (p1[0] == p2[1] && p2[1] == p3[1] && p3[1] == p4[1]) return false;
        // x, y; y, -x; -x, -y; -y, x
        int b1, b2;
        b1 = p1[0] - p2[0], b2 = p1[1] - p2[1];
        if (b2 == p2[0] - p3[0] && -b1 == p2[1] - p3[1]){
            if (-b1 == p3[0] - p4[0] && -b2 == p3[1] - p4[1] 
                && -b2 == p4[0] - p1[0] && b1 == p4[1] - p1[1]) return true;
        }else if (b2 == p2[0] - p4[0] && -b1 == p2[1] - p4[1]){
            if (-b1 == p4[0] - p3[0] && -b2 == p4[1] - p3[1] 
                && -b2 == p3[0] - p1[0] && b1 == p3[1] - p1[1]) return true;
        }
        b1 = p1[0] - p3[0], b2 = p1[1] - p3[1];
        if (b2 == p3[0] - p2[0] && -b1 == p3[1] - p2[1]){
            if (-b1 == p2[0] - p4[0] && -b2 == p2[1] - p4[1] 
                && -b2 == p4[0] - p1[0] && b1 == p4[1] - p1[1]) return true;
        }else if (b2 == p3[0] - p4[0] && -b1 == p3[1] - p4[1]){
            if (-b1 == p4[0] - p2[0] && -b2 == p4[1] - p2[1] 
                && -b2 == p2[0] - p1[0] && b1 == p2[1] - p1[1]) return true;
        }
        b1 = p1[0] - p4[0], b2 = p1[1] - p4[1];
        if (b2 == p4[0] - p2[0] && -b1 == p4[1] - p2[1]){
            if (-b1 == p2[0] - p3[0] && -b2 == p2[1] - p3[1] 
                && -b2 == p3[0] - p1[0] && b1 == p3[1] - p1[1]) return true;
        }else if (b2 == p4[0] - p3[0] && -b1 == p4[1] - p3[1]){
            if (-b1 == p3[0] - p2[0] && -b2 == p3[1] - p2[1] 
                && -b2 == p2[0] - p1[0] && b1 == p2[1] - p1[1]) return true;
        }
        return false;
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
