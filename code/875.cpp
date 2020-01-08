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
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = 0;
        long long sum = 0;
        for (int i: piles) r = max(r, i), sum += i;
        l = max(1ll, sum / H);
        while (r > l){
            int mid = (l + r) >> 1, cnt = 0;
            for (int i: piles) cnt += 1 + (i - 1) / mid;
            if (cnt > H) l = mid + 1;
            else r = mid;
        }
        return l;
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
