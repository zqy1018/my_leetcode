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
    double r, x, y, pi;
    Solution(double radius, double x_center, double y_center) {
        r = radius, x = x_center, y = y_center;
        srand(2131231);
    }
    
    vector<double> randPoint() {
        double a, b;
        for (; ; ){
            a = (2.0 * rand() / RAND_MAX - 1.0) * r;
            b = (2.0 * rand() / RAND_MAX - 1.0) * r;
            if (a * a + b * b > r * r)
                continue;
            else break;
        }
        return vector<double>{x + a, y + b};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
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
