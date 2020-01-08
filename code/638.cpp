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
    map<vector<int>, int> mp;
    int k, sp_size;
    void dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        mp[needs] = INT_MAX;
        vector<int> tmp = needs;
        for (int i = 0; i < sp_size; ++i){
            bool flag = true;
            for (int j = 0; j < k; ++j){
                needs[j] -= special[i][j];
                if (needs[j] < 0) flag = false;
            }
            if (flag){
                if (!mp.count(needs))
                    dfs(price, special, needs);
                mp[tmp] = min(mp[tmp], mp[needs] + special[i][k]);
            }
            for (int j = 0; j < k; ++j)
                needs[j] += special[i][j];
        }
        int cnt = 0;
        for (int i = 0; i < k; ++i) cnt += needs[i] * price[i];
        mp[needs] = min(mp[needs], cnt);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        k = price.size(), sp_size = special.size();
        vector<int> zeros(k, 0);
        mp[zeros] = 0;
        if (!mp.count(needs)) dfs(price, special, needs);
        return mp[needs];
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
