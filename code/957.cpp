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
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int ds[64] = {0}, nds[64] = {0}, cur = 0;
        for (int i = 0; i < 8; ++i)
            cur = cur << 1 | cells[i];
        int day1 = 0, totd = 0, T;
        for (int i = 6, j = (1 << 7) + (1 << 5); i >= 1; --i, j >>= 1){
            if ((cur & j) == j || (cur & j) == 0) 
                day1 |= (1 << i);
        }
        ds[day1 >> 1] = ++totd, nds[totd] = day1, cur = day1, day1 = 0;
        for(; N > totd; ){
            for (int i = 6, j = (1 << 7) + (1 << 5); i >= 1; --i, j >>= 1)
                if ((cur & j) == j || (cur & j) == 0) 
                    day1 |= (1 << i);
            if (ds[day1 >> 1]) {
                T = totd - ds[day1 >> 1] + 1;
                N -= ds[day1 >> 1];
                cur = nds[N % T + ds[day1 >> 1]];
                break;
            }
            ds[day1 >> 1] = ++totd, nds[totd] = day1, cur = day1, day1 = 0;
        }
        vector<int> ans;
        for (int i = (1 << 7); i; i >>= 1)
            ans.push_back((cur & i) ? 1: 0);
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
